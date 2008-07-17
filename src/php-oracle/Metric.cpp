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


#include "AstNode.h"
#include "tree.h"
#include "AstContainer.h"
#include "Metric.h"
#include "Utils.h"
#include <cstdlib>
#include <string>
#include <map>
#include <iostream>
#include <stack>
using namespace std;

std::ostream& operator<<(std::ostream& stream, const NumericResult& num) {
	stream << num.toString();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const MetricResult& metric) {
	stream << "(main=" << metric.main << ')';
	for (map<string, NumericResult>::const_iterator iter=metric.storage.begin(); iter!=metric.storage.end();++iter)
		stream << '(' << iter->first << "=" <<	iter->second << ')';
	return stream;
}


MetricResult NumberFunctions::operator()(const tree<AstNode>&, const MapClasses* classes , const MapVariables* vars, 
                                         const MapFunctions *func, const MapAssignments *assigns, const MapVarEquivalent *equiv)
{
	MetricResult  result;
	NumericResult num;
	// return the number of functions in the current source code
	num = func->size();
	result.main = num;
	return result;
}


MetricResult NumberSinks::operator()(const tree<AstNode>& tr, const MapClasses* classes , const MapVariables* vars,
                                     const MapFunctions *func, const MapAssignments *assigns, const MapVarEquivalent *equiv)
{
	MetricResult  result;
	NumericResult num;
	unsigned n = 0;
	// Get the outputs functions in the tree-functions. if there is one, just add the function into the list of sensitive
	std::map<std::string, BoxedFunction> boxedFunctions = ast->getBoxedFunctions();
	for (std::map<std::string, BoxedFunction>::iterator iter=boxedFunctions.begin();iter!=boxedFunctions.end();++iter)
	{
		// iterate through the boxedFunctions output
		bool add = false;
		for(MapFunctions::iterator jter=iter->second.output.begin();jter!=iter->second.output.end();++jter) {
			if (find(sensitive.begin(), sensitive.end(), jter->first) != sensitive.end()) {
				add = true;
				break;
			}
		}
		if (add) {
			if (find(sensitive.begin(), sensitive.end(), iter->first) == sensitive.end())
				sensitive.push_back(iter->first);
		}
	}

	// return the number of functions in the current source code
	for (tree<AstNode>::iterator iter = tr.begin(); iter != tr.end(); ++iter) {
		string t = iter->getType();
		if (t == "unticked_function_declaration_statement") {
			iter = tr.end(iter);
		}
		else if (t == "function_call") {
			tree<AstNode>::iterator son = tr.begin(iter);
			if (son->getType() == "T_STRING") {
				tree<AstNode>::iterator  textable = tr.begin(son);
				if (textable->getType() == "text" && find(sensitive.begin(), sensitive.end(), textable->getValue()) != sensitive.end()) {
					n++;
				}
			}
		}
		else if (t == "unticked_statement" || t == "expr_without_variable") {
			tree<AstNode>::iterator son = tr.begin(iter);
			if (utils::start_with(son->getType(), "T_")) {
				tree<AstNode>::iterator  textable = tr.begin(son);
				if (textable->getType() == "text" && find(sensitive.begin(), sensitive.end(), textable->getValue()) != sensitive.end()) {
					n++;
				}
			}
		}
	}
	num = n;
	result.main = num;
	return result;
}


MetricResult NumberResources::operator()(const tree<AstNode>& tr, const MapClasses* classes , const MapVariables* vars,
                                     const MapFunctions *func, const MapAssignments *assigns, const MapVarEquivalent *equiv)
{
	MetricResult  result;
	NumericResult num;
	unsigned n = 0;
	// Get the outputs functions in the tree-functions. if there is one, just add the function into the list of sensitive
	std::map<std::string, BoxedFunction> boxedFunctions = ast->getBoxedFunctions();
	for (std::map<std::string, BoxedFunction>::iterator iter=boxedFunctions.begin();iter!=boxedFunctions.end();++iter)
	{
		// iterate through the boxedFunctions output
		bool add = false;
		for(MapFunctions::iterator jter=iter->second.input.begin();jter!=iter->second.input.end();++jter) {
			if (find(taintedinput.begin(), taintedinput.end(), jter->first) != taintedinput.end()) {
				add = true;
				break;
			}
		}
		if (add) {
			if (find(taintedinput.begin(), taintedinput.end(), iter->first) == taintedinput.end())
				taintedinput.push_back(iter->first);
		}
	}
	// return the number of functions in the current source code
	for (tree<AstNode>::iterator iter = tr.begin(); iter != tr.end(); ++iter) {
		string t = iter->getType();
		if (t == "unticked_function_declaration_statement") {
			iter = tr.end(iter);
		}
		else if (t == "function_call") {
			tree<AstNode>::iterator son = tr.begin(iter);
			if (son->getType() == "T_STRING") {
				tree<AstNode>::iterator  textable = tr.begin(son);
				if (textable->getType() == "text" && find(taintedinput.begin(), taintedinput.end(), textable->getValue()) != taintedinput.end()) {
					n++;
				}
			}
		}
		else if (t == "unticked_statement" || t == "expr_without_variable") {
			tree<AstNode>::iterator son = tr.begin(iter);
			if (utils::start_with(son->getType(), "T_")) {
				tree<AstNode>::iterator  textable = tr.begin(son);
				if (textable->getType() == "text" && find(taintedinput.begin(), taintedinput.end(), textable->getValue()) != taintedinput.end()) {
					n++;
				}
			}
		}
	}

	// add the boxed source





	num = n;
	result.main = num;
	return result;
}





MetricResult NumberVariables::operator()(const tree<AstNode>&, const MapClasses* classes , const MapVariables* vars,
                                         const MapFunctions *func, const MapAssignments *assigns, const MapVarEquivalent *equiv)
{
	MetricResult  result;	
	NumericResult num;
	// return the number of functions in the current source code
	num = vars->size();
	result.main = num;
	return result;
}


MetricResult NumberClasses::operator()(const tree<AstNode>&, const MapClasses* classes , const MapVariables* vars, 
                                         const MapFunctions *func, const MapAssignments *assigns, const MapVarEquivalent *equiv)
{
	MetricResult  result;	
	NumericResult num;
	// return the number of functions in the current source code
	num = classes->size();
	result.main = num;
	return result;
}


MetricResult NumberInput::operator()(const tree<AstNode>& tr, const MapClasses* classes , const MapVariables* vars, 
                                         const MapFunctions *func, const MapAssignments *assigns, const MapVarEquivalent *equiv)
{
	MetricResult  result;	
	unsigned num=0;
	// Get the pointer on the tree with input entry defintion
	list<string> scanned;
	string temp,fullvarname;
	const tree<AstNode>*  def = defAST.getTreeConstPtr();
	// Go through all variables
	for(MapVariables::const_iterator iter=vars->begin(); iter!=vars->end();++iter)
	{
		for (AstVarBaseList::const_iterator jter=iter->second.begin();jter!=iter->second.end();++jter)
		{
			temp = jter->name;
			fullvarname = jter->name;
			if (jter->index.length() > 0) {
				 fullvarname += ('[' + jter->index + ']');
			}
			for (tree<AstNode>::leaf_iterator lter=def->begin_leaf();lter!=def->end_leaf();++lter)
			{
				if (lter->getValue() == temp) {
					if (find(scanned.begin(), scanned.end(), fullvarname) == scanned.end()) {
						// Am I looking for an array somewhere?
						tree<AstNode>::iterator tter=tr.parent(tr.begin(jter->position));
						if (tr.number_of_children(tter) > 1)
							num++;							
						scanned.push_back(fullvarname);
					}						
				}
			}
		}
	}
	result.main = num;
	return result;
}


/**
	Same as NumberInput but counting with the dataflow:

	a = $_GET['b']
	b = $_GET['b']

	=> 2
*/
MetricResult NumberDiffuseInputs::operator()(const tree<AstNode>& tr, const MapClasses* classes , const MapVariables* vars,
                                         const MapFunctions *func, const MapAssignments *assigns, const MapVarEquivalent *equiv)
{
	MetricResult  result;	
	unsigned num=0;
	// Get the pointer on the tree with input entry defintion
	list<string> scanned;
	string temp,fullvarname;
	const tree<AstNode>*  def = defAST.getTreeConstPtr();
	
	// Go through all variables
	for(MapVariables::const_iterator iter=vars->begin(); iter!=vars->end();++iter)
	{
		for (AstVarBaseList::const_iterator jter=iter->second.begin();jter!=iter->second.end();++jter)
		{
			temp = jter->name;
			fullvarname = jter->name;
			if (jter->index.length() > 0) {
				 fullvarname += ('[' + jter->index + ']');
			}
			for (tree<AstNode>::leaf_iterator lter=def->begin_leaf();lter!=def->end_leaf();++lter)
			{
				if (lter->getValue() == temp) {
					if (find(scanned.begin(), scanned.end(), fullvarname) == scanned.end()) {
						// Am I looking for an array somewhere?
						tree<AstNode>::iterator tter=tr.parent(tr.begin(jter->position));
						if (tr.number_of_children(tter) > 1)
							num++;							
						scanned.push_back(fullvarname);
					}						
				}
			}
		}
	}

	// Then, add the assignments variables recursivle of the scanned listen
	// cerr << "Equivalences:" << endl;
	for (MapAssignments::const_iterator iter = assigns->begin(); iter != assigns->end(); ++iter)
	{
		fullvarname = iter->second.name;
		if (iter->second.index.length() > 0) {
			 fullvarname += ('[' + iter->second.index + ']');
		}
		
		string tname = iter->first.name;
		if (iter->first.index.length() > 0) {
			 tname += ('[' + iter->first.index + ']');
		}
		if (find(scanned.begin(), scanned.end(), fullvarname) != scanned.end()){
			num++;	
		}
	}
	result.main = num;
	return result;
}


MetricResult NumberSunkDiffuseInputs::operator()(const tree<AstNode>& tr, const MapClasses* classes , const MapVariables* vars,
                                         const MapFunctions *func, const MapAssignments *assigns, const MapVarEquivalent *equiv)
{
	MetricResult  result;
	unsigned num = 0;
	
	// Get the pointer on the tree with input entry defintion
	list<string> scanned, varsList;
	list<VarBase> varBaseList;
	string temp,fullvarname;
	const tree<AstNode>*  def = defAST.getTreeConstPtr();

	std::map<std::string, BoxedFunction> boxedFunctions = ast->getBoxedFunctions();
	for (std::map<std::string, BoxedFunction>::iterator iter=boxedFunctions.begin();iter!=boxedFunctions.end();++iter)
	{
		// iterate through the boxedFunctions output
		bool add = false;
		for(MapFunctions::iterator jter=iter->second.output.begin();jter!=iter->second.output.end();++jter) {
			if (find(sensitive.begin(), sensitive.end(), jter->first) != sensitive.end()) {
				add = true;
				cout << "Add this function into sensitive sinks: '" << iter->first <<  "' because of -- " << jter->first <<endl;
				break;
			}
		}
		if (add) {
			if (find(sensitive.begin(), sensitive.end(), iter->first) == sensitive.end())
				sensitive.push_back(iter->first);
		}
	}

	// Go through all variables
	for(MapVariables::const_iterator iter=vars->begin(); iter!=vars->end();++iter)
	{
		for (AstVarBaseList::const_iterator jter=iter->second.begin();jter!=iter->second.end();++jter)
		{
			temp = jter->name;
			fullvarname = jter->name;
			if (jter->index.length() > 0) {
				 fullvarname += ('[' + jter->index + ']');
			}
			for (tree<AstNode>::leaf_iterator lter=def->begin_leaf();lter!=def->end_leaf();++lter)
			{
				if (lter->getValue() == temp) {
					if (find(scanned.begin(), scanned.end(), fullvarname) == scanned.end()) {
						// Am I looking for an array somewhere?
						tree<AstNode>::iterator tter=tr.parent(tr.begin(jter->position));
						//if (tr.number_of_children(tter) > 1)
						//	num++;							
						scanned.push_back(fullvarname);
						varsList.push_back(fullvarname);
						varBaseList.push_back(*jter);
					}						
				}
			}
		}
	}

	// Then, add the assignments variables recursivly of the scanned listen
	string asname, bsname;

	list<string> curVars, forbidden;

	for (list<string>::const_iterator jter=varsList.begin(); jter!=varsList.end();++jter) 
		if (find(curVars.begin(),curVars.end(),*jter) == curVars.end())
			curVars.push_back(*jter);
	while(curVars.size() > 0)
	{
		// take the first element on the stack
		string elmt = *(curVars.begin());
		// look at all assignement
		for (MapAssignments::const_iterator iter = assigns->begin(); iter != assigns->end(); ++iter)
		{
			asname = iter->first.name;
			if (iter->first.index.length() > 0) {
				 asname += ('[' + iter->first.index + ']');
			}
			bsname = iter->second.name;
			if (iter->second.index.length() > 0) {
				 bsname += ('[' + iter->second.index + ']');
			}
			if (bsname == elmt && find(forbidden.begin(),forbidden.end(),asname) == forbidden.end()) {
				if (find(curVars.begin(),curVars.end(),asname) == curVars.end())
					curVars.push_back(asname);
				if (find(varsList.begin(),varsList.end(),asname) == varsList.end()) {
					varsList.push_back(asname);
					varBaseList.push_back(iter->first);
				}
			}
		}
		curVars.pop_front();
		forbidden.push_back(elmt);
	}

	// What about the equivalences now?
	for (MapVarEquivalent::const_iterator iter = equiv->begin(); iter != equiv->end(); ++iter)
	{
		asname = iter->first.name;
		if (iter->first.index.length() > 0) {
			 asname += ('[' + iter->first.index + ']');
		}
		// does the variable has an equivalence?
		for (AstVarBaseList::const_iterator jter=iter->second.begin(); jter!=iter->second.end();++jter) {
			bsname = jter->name;
			if (jter->index.length() > 0) {
				 bsname += ('[' + jter->index + ']');
			}

			if (find(varsList.begin(),varsList.end(),bsname) != varsList.end()) {
				if (find(varsList.begin(), varsList.end(), asname) == varsList.end()){
					//num++;
					varsList.push_back(asname);
					varBaseList.push_back(iter->first);
				}
			}
		}
	}
	// So, what do we have in the varsList?
	cerr << endl << "####################" << endl << "List of variables:" << endl;
	for(list<string>::const_iterator k=varsList.begin();k!=varsList.end();++k)
		cerr << *k << ',';
	cerr << endl << "####################" << endl << endl;

	string type,function;
	tree<AstNode>::iterator child, parent;
	// Now, for now, for all variables, look if there are called in sensitive sinks
	for (tree<AstNode>::iterator iter=tr.begin();iter!=tr.end();++iter)
	{
		type = iter->getType();
		//
		if (type == "function_call"
		|| (utils::start_with(type, "T_") && (type != "T_CONSTANT_ENCAPSED_STRING" && type != "T_VARIABLE" && type != "T_STRING") )) {
			// we have a possible position
			if (type == "function_call")
			{
				// get the T_STRING value
				for (tree<AstNode>::iterator jter=iter;jter!=tr.end(iter);++jter) {
					if (jter->getType() == "T_STRING") {
						// gotcha!
						child = jter;
						break;
					}
				}
				// get the function name
				if (tr.number_of_children(child) == 1) {
					function = tr.child(child,0)->getValue();
					if (find(sensitive.begin(),sensitive.end(),function) != sensitive.end())
					{
						// we now have a sensitive sinks, let's look in the parameters
						list<VarBase> subVariables= ast->getSubVariables(iter);
						// print subvariable's
						//cerr << function << '(';
						//for (list<VarBase>::const_iterator vter=subVariables.begin();vter!=subVariables.end();++vter)
						//	cerr << *vter << ',';
						//cerr << ')' << endl;

						for (list<VarBase>::const_iterator vter=subVariables.begin();vter!=subVariables.end();++vter)
						{
							string tname = vter->name;
							if (vter->index.length() > 0) {
								 tname += ('[' + vter->index + ']');
							}
							if (find(varsList.begin(), varsList.end(), tname) != varsList.end()) {
								// found one!
								num++;
								cerr << "(function_call) Sink |Diffuse input : " << function << " (" << tname << ")" << endl;
								break;
							}
						}
					}
				}
				// skipping...
				iter = child;
			}
			else
			{
				function = "";
				// get name of the T_ call ? die, echo, print, assert ?
				tree<AstNode>::iterator jter = tr.begin(iter);
				for (;jter!=tr.end(iter);++jter) {
					if (jter->getType() == "text") {// gotcha!
						function = jter->getValue();
						break;
					}
				}
				if (find(sensitive.begin(),sensitive.end(),function) != sensitive.end())
				{
				
					// we now have a sensitive sinks, let's look in the parameters
					list<VarBase> subVariables= ast->getSubVariables(tr.parent(iter));
					// print subvariable's
					//cerr << function << '(';
					//for (list<VarBase>::const_iterator vter=subVariables.begin();vter!=subVariables.end();++vter)
					//	cerr << *vter << ',';
					//cerr << ')' << endl;

					for (list<VarBase>::const_iterator vter=subVariables.begin();vter!=subVariables.end();++vter)
					{
						string tname = vter->name;
						if (vter->index.length() > 0) {
							 tname += ('[' + vter->index + ']');
						}
						//cerr << tname << endl;
						if (find(varsList.begin(), varsList.end(), tname) != varsList.end()) {
							// found one!
							num++;
							cerr << "(language_dependant) Sink |Diffuse input : " << function << " | " << tname << endl;
							break;
						}
						else
						{
							// maybe we can count it.
							// echo $array[$i] in a loop or with the index
							if (vter->index.length() > 0)
							{
								// look at if there is a var
								for (list<VarBase>::const_iterator bter=varBaseList.begin();bter!=varBaseList.end();++bter)
								{
									if (bter->name == vter->name && find(varsList.begin(), varsList.end(), vter->index) == varsList.end()) {
										// if the index is a variable?
										if (vter->index[0] == '$') {
											num++;
											cerr << "(language_dependant) Sink |Diffuse input : " << function << " | " << tname << endl;
										}
										break;
									}
								}
							}
						}
					}
				}
				// skipping...
				iter = jter;
			}
		}
	}
	
	
	
	result.main = num;
	return result;
}
