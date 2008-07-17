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
#include "Translation.h"
#include <vector>
#include <list>
#include <string>
#include <map>
#include <fstream>
using namespace std;


list<string> classVarNames;


#define CPPHEADERSIZE 2
const string cppheader[CPPHEADERSIZE] = {
	"#include <iostream>\n",
	"#include \"libphp.h\"\n\n"
};


string cppBufferize(const string& __in) {
	string buf = "";

	return buf;
}

string indent(unsigned nbIndent) {
	string r = "";
	for (unsigned i=0;i<nbIndent;i++)
		r += '\t';
	return r;
}

/*

	chars = "{}"
	for l in r:
		if len(l) == 0 or l == "\n":
			string += " "
		elif l in chars:
			string += l
			if l == "}": indent -= 1
			formated.append((indent,string))
			if l == "{": indent += 1
			string = ""
		else:
			string += l
			if l == ';' and 'for' not in string:
				formated.append((indent,string))
				string = ""

*/

void StringBuffer::format() {
	string out="";
	string temp="";
	unsigned nind = 0;
	for (std::string::const_iterator iter=buffer.begin();iter!=buffer.end();++iter)
	{
		const char c = *iter;
		if (c == '\n') {
			continue;
		}
		else if (c == '{' || c == '}') {
			temp += c;
			if (c == '}') nind--;
			out += (indent(nind) + temp + "\n");
			if (c == '{') nind++;
			temp = "";
		}
		else {
			temp += c;
			if (c == ';') {
				out += (indent(nind) + temp + "\n");
				temp = "";
			}
		}
	}
	buffer = out;

}


void StringBuffer::write(const std::string& fname) {
	ofstream out(fname.c_str());
	out << buffer;
	out.close();
}


std::ostream& operator<<(std::ostream& stream, const StringBuffer& b) {
	stream << b.buffer << std::endl;
	return stream;
}


string varname(const string& phpname, bool correctQuote = false) {
	string name;
	for (string::const_iterator i=phpname.begin();i!=phpname.end();++i) {
		if (*i == '$')
			continue;
		else if (correctQuote and *i == '\'')
			name += '"';
		else
			name += *i;
	}
	return name;
}



string getNodeValue(const tree<AstNode>::iterator& start, const string& type, const tree<AstNode>& tr)
{
	for (tree<AstNode>::iterator iter=tr.begin(start);iter!=tr.end(start);++iter) {
		if (iter->getType() == type) {
			for (;iter->getType() != "text" && iter!=tr.end(start);++iter)
				;
			if (iter->getType() == "text")
				return iter->getValue();
			else
				return string();
		}
	}
	return string();
}

tree<AstNode>::iterator getNodeIter(const tree<AstNode>::iterator& start, const string& type, const tree<AstNode>& tr)
{
	for (tree<AstNode>::iterator iter=tr.begin(start);iter!=tr.end(start);++iter) {
		if (iter->getType() == type)
			return iter;
	}
	return tr.end();
}

bool functionReturnValue(const tree<AstNode>::iterator& start, const tree<AstNode>& tr)
{
	for (tree<AstNode>::iterator iter=tr.begin(start);iter!=tr.end(start);++iter) {
		if (iter->getType() == "T_RETURN") {
			tree<AstNode>::iterator p = tr.parent(iter);
			if (tr.number_of_children(p) > 2)
				return true;
		}
	}
	return false;
}

bool isAChildrenOf(const tree<AstNode>::iterator& start, const string& type, const tree<AstNode>& tr)
{
	unsigned nC = tr.number_of_children(start);
	if (nC > 0) {
		for (unsigned i=0;i<nC;i++) {
			if (tr.child(start, i)->getType() == type)
				return true;
		}
	}
	return false;
}

bool classAssignement(const tree<AstNode>::iterator& start, const tree<AstNode>& t) {
	for (tree<AstNode>::iterator iter=t.begin(start);iter!=t.end(start);++iter) {
		if (iter->getType() == "T_NEW") {
			return true;
		}
	}
	return false;
}

string className(const tree<AstNode>::iterator& start, const tree<AstNode>& t) {
	for (tree<AstNode>::iterator iter=t.begin(start);iter!=t.end(start);++iter) {
		if (iter->getType() == "class_name_reference") {
			for (tree<AstNode>::iterator jter=t.begin(iter);jter!=t.end(iter);++jter) {
				if (jter->getType() == "text") {
					return jter->getValue();
				}
			}
			return string();
		}
	}
	return string();
}


string subVarName(const tree<AstNode>::iterator& it, const tree<AstNode>& tr)
{
	tree<AstNode>::iterator iter = it;
	// go the the variable
	for (;iter != tr.end(it); ++iter) {
		if (iter->getType() == "reference_variable")
		{
			unsigned nbchilds = tr.number_of_children(iter);
			if (nbchilds == 1) {
				if (tr.child(iter, 0)->getType() == "compound_variable") {
					// single variables
					tree<AstNode>::iterator var = iter;
					for(;var->getType() != "text"; ++var)
						;
					return (var->getValue());
				}
			}
			else if (nbchilds == 4) {
				// array ?
				tree<AstNode>::iterator array = tr.child(iter, 0);
				tree<AstNode>::iterator index = tr.child(iter, 2);
				for(;array->getType() != "text" && array != tr.end(); ++array)
					;
				for(;index->getType() != "text" && index != tr.end(); ++index)
					;
				return array->getValue() + "[" + index->getValue() + "]";
			}
		}
		else if (iter->getType() == "expr_without_variable")
		{
			// go to the T_VARIABLE
			tree<AstNode>::iterator var = iter;
			for(;var->getType() != "T_VARIABLE"; ++var)
				;
			var = tr.child(var, 0);
			return var->getValue();
		}
	}
	// backtrack for: strings, functions, class
	return string();
}

void writeSiblingsCPP(const tree<AstNode>& t, const tree<AstNode>::iterator& iRoot, StringBuffer& buf,
                      bool inString = false, bool inFct = false, bool inMain = false, bool inClass = false, bool inFctCall = false)
{
	if(t.empty())
		return;
	string type = iRoot->getType();
	if (type == "root") {
		tree<AstNode>::sibling_iterator iChildren = t.begin(iRoot);
		writeSiblingsCPP(t,iChildren,buf,inString,inFct,inMain,inClass,inFctCall);
	}
	else if (t.number_of_children(iRoot) == 0) {
		if (iRoot->getValue().length() > 0) {
			if (iRoot->getValue() == ".") { /* concatenate transformation */  buf << " + "; }
			else if (t.parent(iRoot)->getType() == "T_ENCAPSED_AND_WHITESPACE")
				buf << (varname(iRoot->getValue(), false) + " ");
			else
				buf << (varname(iRoot->getValue(), true) + " ");
		}
	}
	else {
		int siblingNum;
		tree<AstNode>::sibling_iterator iChildren;
		if (type == "T_ECHO" or type == "T_INCLUDE" or type == "T_PRINT") {
			// gotta be a function
			tree<AstNode>::iterator parent = t.parent(iRoot); // go to the parent in order to get all information
			string funcName = getNodeValue(parent, type, t);
			string contentNodeName = "echo_expr_list";
			if (type == "T_INCLUDE" or type == "T_PRINT") {
				contentNodeName = "expr";
			}
			// must be always true, otherwise, the AST is ill-formed
			buf << (funcName + "(");
			writeSiblingsCPP(t,getNodeIter(parent, contentNodeName, t),buf,inString,inFct,inMain,inClass,inFctCall);
			buf << "); ";
		}
		else if (type == "expr_without_variable" && t.number_of_children(iRoot) == 3 
		&&       t.child(iRoot,1)->getType() == "CHAR61"
		&&       classAssignement(t.child(iRoot,2), t)) { // assignement + class + new 
			string cname = className(t.child(iRoot,2), t);
			if (cname.length() > 0) {
				string v = varname(subVarName(t.child(iRoot,0), t));
				buf << cname << "* " << v << " = new " << cname << "()\n";
				classVarNames.push_back(v);
			}
			else {
				for (iChildren = t.begin(iRoot), siblingNum = 0; iChildren != t.end(iRoot); ++iChildren)
				{
					string subtype = iChildren->getType();
					if (subtype == "T_ECHO" or subtype == "T_INCLUDE" or subtype == "T_PRINT") {
						writeSiblingsCPP(t,iChildren,buf,inString,inFct,inMain,inClass,inFctCall);
						break;
					}
					else if (inMain && (subtype == "unticked_function_declaration_statement" ||  subtype == "unticked_class_declaration_statement")) {
						continue;
					}
					else
						writeSiblingsCPP(t,iChildren,buf,inString,inFct,inMain,inClass,inFctCall);
				}
			}
		}
		else {
			for (iChildren = t.begin(iRoot), siblingNum = 0; iChildren != t.end(iRoot); ++iChildren)
			{
				string subtype = iChildren->getType();
				if (subtype == "T_ECHO" or subtype == "T_INCLUDE" or subtype == "T_PRINT") {
					writeSiblingsCPP(t,iChildren,buf,inString,inFct,inMain,inClass,inFctCall);
					break;
				}
				else if (inMain && (subtype == "unticked_function_declaration_statement" ||  subtype == "unticked_class_declaration_statement")) {
					continue;
				}
				else
					writeSiblingsCPP(t,iChildren,buf,inString,inFct,inMain,inClass,inFctCall);
			}
		}
	}
}

void writeCPP(const tree<AstNode>& tr, StringBuffer& buf)
{
	if (tr.empty()) {
		throw length_error("writeCPP - The AST tree is empty");
		return;
	}
	for(tree<AstNode>::sibling_iterator iRoots = tr.begin(); iRoots != tr.end(); iRoots++) {
		writeSiblingsCPP(tr,iRoots,buf);
	}
}



void addFunctionCpp(const tree<AstNode>::iterator& start, const tree<AstNode>& tr, StringBuffer& buffer, bool fromClass = false, const string cname = "")
{
	string fname;
	vector<string> paramVars;
	bool returnValue = functionReturnValue(start, tr);
	fname = getNodeValue(start, "T_STRING", tr);
	
	if (fromClass)
	{
		if (utils::start_with(fname,"__")) {
			// looks like a constructor, copy etc.
			if (fname == "__construct")
				fname = cname;
			else if (fname == "__destruct")
				fname = "~" + cname;
			else if (fname == "__clone") // I'll do by myself!
				return;
		}
	}

	tree<AstNode>::iterator params = getNodeIter(start, "parameter_list", tr);
	if (tr.number_of_children(params) > 0) {
		// fill paramVars
		for (tree<AstNode>::iterator iter=tr.begin(params);iter!=tr.end(params);++iter) {
			if (iter->getType() == "T_VARIABLE") {
				paramVars.push_back(varname(tr.child(iter, 0)->getValue()));
			}
		}
	}
	string decl = "";
	if (returnValue)
		decl += "PhpObject ";
	else if (fname != cname)
		decl += "void ";
	decl += fname;
	decl += "( ";
	unsigned t = paramVars.size();
	if (t > 0) {
		decl += ("PhpObject& loc_" + paramVars[0]);
		for (unsigned i=1;i<t;i++)
		decl += (", PhpObject& " + paramVars[i]);
	}
	decl += " ) {\n";
	buffer << (decl);
	StringBuffer localFuncContent;
	tree<AstNode>::iterator content;

	content = getNodeIter(start, "inner_statement_list", tr);

	writeSiblingsCPP(tr, content, localFuncContent, false, true);
	for (vector<string>::const_iterator iter=paramVars.begin();iter!=paramVars.end();++iter) {
		localFuncContent.replace(" " + *iter + " ", " loc_" + *iter + " ");
	}
	buffer << localFuncContent;
	buffer << ("}\n");
}


void addClassCpp(const tree<AstNode>::iterator& start, const tree<AstNode>& tr, StringBuffer& buffer)
{
	// Check for the class name
	string cname, extend="";
	cname = getNodeValue(start, "T_STRING", tr);
	tree<AstNode>::iterator extends = getNodeIter(start, "extends_from", tr);
	
	buffer << "class " + cname;

	if (tr.number_of_children(extends) > 0) {
		for (tree<AstNode>::iterator iter=tr.begin(extends);iter!=tr.end(extends);++iter) {
			if (iter->getType() == "T_STRING") {
				extend = tr.child(iter, 0)->getValue();
				break;
			}
		}
		buffer << " : public " + extend;
	}
	buffer << "{\n";

	tree<AstNode>::iterator methodList = getNodeIter(start, "class_statement_list", tr);
	// Add the methods in the content

	map<string, tree<AstNode>::iterator> specialFunctions;

	// Check if there is contructor
	for (tree<AstNode>::iterator iter=tr.begin(methodList);iter!=tr.end(methodList);++iter) {
		if (iter->getType() == "class_statement") {
			for (tree<AstNode>::iterator jter=tr.begin(iter);jter!=tr.end(iter);++jter) {
				if (jter->getType() == "T_STRING") {
					jter = tr.child(jter, 0);
					if (jter->getType() == "text" && utils::start_with(jter->getValue(), "__")) {
						// special function
						specialFunctions.insert(make_pair(jter->getValue(), iter));
						break;
					}
				}
			}
		}
	}
	
	// Add the function definitions
	for (tree<AstNode>::iterator iter=tr.begin(methodList);iter!=tr.end(methodList);++iter)
	{
		if (iter->getType() == "class_statement")
		{
			//cout << "One call to method? declaration..." << endl;
			addFunctionCpp(iter, tr, buffer, true, cname);
		}
	}

	if (specialFunctions.find("__construct") == specialFunctions.end()) {
		// write the default constructor
		buffer << ("\n " + cname + "() {}\n");
	}
	if (specialFunctions.find("__destruct") == specialFunctions.end()) {
		// write the default constructor
		buffer << ("\n ~" + cname + "() {}\n");
	}
	buffer << ("\n " + cname + "(const "+ cname + "& ____c) {}\n");
	buffer << "\n};\n";
}

StringBuffer Ast2Cpp::operator()(const tree<AstNode>& tr, const MapClasses* classes, const MapVariables* vars, 
	                             const MapFunctions *func, const MapAssignments *assigns, const MapVarEquivalent *equiv)
{
	StringBuffer buffer, beg;
	classVarNames.clear();

	for (unsigned i=0;i<CPPHEADERSIZE;i++) {
		beg << (cppheader[i]);
	}

	// Add the classes definitions
	for (tree<AstNode>::iterator iter=tr.begin();iter!=tr.end();++iter)	{
		if (iter->getType() == "unticked_class_declaration_statement")
			addClassCpp(iter, tr, buffer);
	}

	// Add the function definitions
	for (tree<AstNode>::iterator iter=tr.begin();iter!=tr.end();++iter)
	{
		if (iter->getType() == "unticked_function_declaration_statement")
		{
			addFunctionCpp(iter, tr, buffer);
		}
	}

	// Add the main
	buffer << ("\n\nint main() {\n");
	//cout << "Main" << endl;
	writeSiblingsCPP(tr, tr.begin(), buffer,false,false,true);
	buffer << ("return 0;\n}\n\n");

	// Add all variables as global
	for(MapVariables::const_iterator iter = vars->begin(); iter != vars->end(); ++iter) {
		if (find(classVarNames.begin(),classVarNames.end(),varname(iter->first)) == classVarNames.end()) {
			string def = "PhpObject " + varname(iter->first) + ";\n";
			beg << (def);
		}
	}
	beg << ("\n");

	buffer.format();
	buffer.insert_begin(beg);
	return buffer;
}



StringBuffer Ast2Php::operator()(const tree<AstNode>& tr, const MapClasses* classes, const MapVariables* vars, 
	                             const MapFunctions *func, const MapAssignments *assigns, const MapVarEquivalent *equiv)
{
	StringBuffer buffer, out;
	// Add the classes definitions
	for (tree<AstNode>::iterator iter=tr.begin();iter!=tr.end();++iter)	{
		if (iter->getType() == "text")
			buffer << iter->getValue() + " ";
	}
	buffer.format();
	out << "<?php\n\n";
	out << buffer;
	out << "\n\n?>";
	return out;
}



