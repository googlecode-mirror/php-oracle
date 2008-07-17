/*------------------------------------------------------------------------------
    This file is part of PHP-AST Project by Romain Gaucher (http://rgaucher.info).

    PHP-AST is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    PHP-AST/ORACLE is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with PHP-AST.  If not, see <http://www.gnu.org/licenses/>.
------------------------------------------------------------------------------*/


#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <map>
#include "AstContainer.h"
#include "AstPath.h"
#include "tree_util.h"
#include "Metric.h"
#include "Translation.h"
#include "Obfuscator.h"
#include "Utils.h"
using namespace std;

list<string> loadConf(const string& fname)
{
	ifstream file(fname.c_str());
	string s;
	list<string> ret;
	if (!file) {
		cerr << "Cannot opent the file..." << endl;
	}
	while(getline(file, s))
	{
		ret.push_back(s);		
	}
	return ret;
}

unsigned loc(const string& fname)
{
	ifstream file(fname.c_str());
	string s;
	unsigned ret = 0;
	if (!file) {
		cerr << "Cannot opent the file..." << endl;
	}
	while(getline(file, s))
		++ret;
	return ret;
}

string xmlentities(const string& str)
{
	string ret;
	for(string::const_iterator iter=str.begin();iter!=str.end();++iter) {
		switch (*iter) {
			case '&' : ret += "&amp;"; break;
			case '<' : ret += "&lt;"; break;
			case '>' : ret += "&gt;"; break;
			case '"' : ret += "&quot;"; break;
			default: ret += *iter; break;
		}
	}
	return ret;
}

string txt_out(const string& fname, map<string, MetricResult>& m)
{
	string ret = "";
	ret += "---------------------\n" ;
	ret += "Analysis of '" + fname + "' [loc=" + to_string<unsigned>(loc(fname)) + "]" + "\n";
	ret += "---------------------\n" ;
	ret += ("Variables: " + m["NumberVariables"].main.toString() + "\n");
	ret += ("Functions: " + m["NumberFunctions"].main.toString() + "\n");
	ret += ("Sinks: " + m["NumberSinks"].main.toString() + "\n");
	ret += ("Classes: " + m["NumberClasses"].main.toString() + "\n");
	ret += ("Resources: " + m["NumberResources"].main.toString() + "\n");
	ret += ("Inputs: " + m["NumberInput"].main.toString() + "\n");
	ret += ("dInputs: " + m["NumberDiffuseInputs"].main.toString() + "\n");
	ret += ("dInputs2Sink: " + m["NumberSunkDiffuseInputs"].main.toString() + "\n");
	return ret;
}

string xml_out(const string& fname, map<string, MetricResult>& m)
{
	string ret = "";
	ret += "<instance>\n";
		ret += ("\t<file loc=\"" + to_string<unsigned>(loc(fname))  + "\" >" + xmlentities(fname) + "</file>\n" );
		ret += ("\t<results>\n");
			ret += ("\t\t<variables>" + m["NumberVariables"].main.toString() + "</variables>\n");
			ret += ("\t\t<functions>" + m["NumberFunctions"].main.toString() + "</functions>\n");
			ret += ("\t\t<sinks>" + m["NumberSinks"].main.toString() + "</sinks>\n");
			ret += ("\t\t<classes  >" + m["NumberClasses"].main.toString() + "</classes  >\n");
			ret += ("\t\t<resources>" + m["NumberResources"].main.toString() + "</resources  >\n");
			ret += ("\t\t<nbInputs>" + m["NumberInput"].main.toString() + "</nbInputs>\n");
			ret += ("\t\t<nbDiffInputs>" + m["NumberDiffuseInputs"].main.toString() + "</nbDiffInputs>\n");
			ret += ("\t\t<nbDiffInputsSunked>" + m["NumberSunkDiffuseInputs"].main.toString() + "</nbDiffInputsSunked>\n");
		ret += ("\t</results>\n");
	ret += "</instance>\n";
	return ret;
}


map<string, MetricResult> computeMetrics(const Ast& ast)
{
	NumberFunctions numbFunctions;
	list<string> sinkList = loadConf("./defs/php/sensitive_sinks.pds");
	list<string> taintList= loadConf("./defs/php/tainted_data_sources.pds");
	list<string> sanitList= loadConf("./defs/php/untainting_data.pds");

	NumberSunkDiffuseInputs numSinks(&ast, "./defs/php.xml", sinkList);
	NumberDiffuseInputs numIntrinsicInputs("./defs/php.xml");
	NumberInput numInputs("./defs/php.xml");
	NumberVariables numVariable;
	NumberFunctions numFunctions;
	NumberClasses numClasses;
	NumberSinks sinks(sinkList,&ast);
	NumberResources resources(taintList,&ast);
	
	MetricResult inputs, intrisics, nsinked, sink;
	MetricResult vars, func, classes, resource;

	vars = ast.compute(&numVariable);
	func = ast.compute(&numFunctions);
	classes = ast.compute(&numClasses);
	inputs = ast.compute(&numInputs);
	intrisics = ast.compute(&numIntrinsicInputs);
	nsinked = ast.compute(&numSinks);
	sink = ast.compute(&sinks);
	resource = ast.compute(&resources);

	// return all.
	map<string, MetricResult> ret;
	ret["NumberSunkDiffuseInputs"] = nsinked;
	ret["NumberDiffuseInputs"]     = intrisics;
	ret["NumberInput"]             = inputs;
	ret["NumberVariables"]         = vars;
	ret["NumberFunctions"]         = func;
	ret["NumberClasses"]           = classes;
	ret["NumberSinks"]             = sink;
	ret["NumberResources"]         = resource;

	return ret;
}



int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		string fname(argv[1]);
		Ast ast(fname);
		utils::replace(fname, ".xml", ".php");
		ast.printInfo(cout);
		map<string, MetricResult> metrics = computeMetrics(ast);
		cout << txt_out(fname, metrics) << endl;
	}
	else if (argc == 4)
	{
		string opt(argv[1]);
		string fname(argv[2]);
		string oput(argv[3]);
		Ast ast(fname);
		if (opt == "--out:cpp" || opt == "--out:php") {
			Translation *trans = 0;
			if (opt[6] == 'c') // cpp
				trans = new Ast2Cpp;
			else
				trans = new Ast2Php;
			StringBuffer o = ast.convert(trans);
			o.write(oput);
		}
		else if (opt == "--out:xml" || opt == "--out:text") {
			map<string, MetricResult> metrics = computeMetrics(ast);
			if (opt[6] == 'x')
				cout << xml_out(fname, metrics) << endl;
			else
				cout << txt_out(fname, metrics) << endl;
		}
		else {
			ofstream fout;
			fout.open(oput.c_str(), ofstream::app);
			map<string, MetricResult> metrics = computeMetrics(ast);
			utils::replace(fname, ".xml", ".php");
			fout << txt_out(fname, metrics) << endl;
			fout.close();
		}
	}
	else if (argc >= 5)
	{
		// php-oracle --obf:control-flow input.xml output.php obfuscation-pattern_1.xml obfuscation-pattern_2.xml ...
		// php-oracle --obf:data-flow        ...
		// php-oracle --obf:data             ...
		// php-oracle --obf:mixed     | analyze the name of the obfuscation pattern path
		vector<string> obf;
		Ast2Cpp ast2cpp;
		Ast2Php ast2php;
		for (unsigned i=4;i<argc;i++)
			obf.push_back(string(argv[i]));
		string fname(argv[2]);
		string output(argv[3]);
		if (string(argv[1]) == "--obf:control-flow")
		{
			Ast ast(fname);
			for (vector<string>::const_iterator iter=obf.begin();iter!=obf.end();++iter) {
				ControlFlow cf(*iter);
				ast.apply(&cf);
			}
			StringBuffer o = ast.convert(&ast2php);
			o.write(output);
		}
	}
	return 0;
}
