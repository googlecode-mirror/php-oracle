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

#include "AstContainer.h"
#include "Utils.h"
#include "Obfuscator.h"
#include "Translation.h"
#include "Metric.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <stack>
using namespace std;

string getContent(xmlNode *a_node) {
	xmlChar *c = xmlNodeGetContent(a_node);
	string ret((char *)c);
	utils::replace(ret, "\n","");
	utils::replace(ret, "\r","");
	utils::replace(ret, "\b","");	
	xmlFree(c);
	return ret;
}

ostream& operator<<(ostream& stream, const Ast& ast) {
	kptree::print_tree_bracketed<AstNode>(ast.tr, stream);
	return stream;
}

ostream& operator<<(ostream& stream, const tree<AstNode>& ast){
	kptree::print_tree_bracketed<AstNode>(ast, stream);
	return stream;	
}

ostream& operator<<(ostream& stream, const tree<AstNode>::iterator& iter){
	stream << iter.node;
	return stream;
}

ostream& operator<<(ostream& stream, const VarBase& v) {
	if (v.index.length() < 1)
		stream << v.name;
	else
		stream << v.name << '[' << v.index << ']';
	return stream;
}


void Ast::apply(Obfuscator* obs) {
	obs->operator()(tr, &classes, &variables, &functions);
}

StringBuffer Ast::convert(Translation* obs) {
	clearInfo();
	fillAstInformation();
	return obs->operator()(tr, &classes, &variables, &functions, &assign, &equivalences);
}


MetricResult Ast::compute(Metric *metric) const
{
	return metric->operator()(tr, &classes, &variables, &functions, &assign, &equivalences);
}


/**
	Get the value of the child node wich parent type is 'nodeName'
*/
string Ast::getChildValue(tree<AstNode>::iterator parent, const string& nodeName) const
{
	tree<AstNode>::sibling_iterator children, textable;
	for (children = tr.begin(parent); children != tr.end(parent); ++children){
		if (children->getType() == nodeName) {
			if (tr.number_of_siblings(children) < 1)
				continue;
			textable = tr.begin(children);
			if (textable->getType() == "text")
				return textable->getValue();
		}
	}
	return string();
}


/**
	Calculate the number of nested variables
*/
unsigned Ast::nbNestedVariables(const tree<AstNode>::iterator& iter) const
{
	unsigned nbVars = 0;
	tree<AstNode>::iterator lter = tr.begin(iter);
	for (;lter!=tr.end(iter);++lter) {
		if (lter->getType() == "T_VARIABLE")
			++nbVars;
	}
	return nbVars;
}

void print_current_list(const list<VarBase>& plop) {
	for (list<VarBase>::const_iterator iter = plop.begin(); iter != plop.end(); ++iter)
		cerr << *iter << " | ";
	cerr << endl;
}


/**
	Detect an assignment in the subtree
*/
bool Ast::detectAssignment(const tree<AstNode>::iterator& iter) const
{
	if (tr.number_of_children(iter) == 3 && tr.child(iter, 1)->getType() == "CHAR61")
		return true;
	return false;
}



/**
	Boxing a source code. Get inputs/outputs in term of functions.
*/
void Ast::sourceBoxing(const tree<AstNode>::iterator& it)
{
	// Get the input
	for (tree<AstNode>::iterator iter = tr.begin(it); iter != tr.end(it); ++iter)
	{
		// skip the functions
		if (iter->getType() == "unticked_function_declaration_statement") {
			iter = tr.end(iter);
		}
		else if (detectAssignment(iter))
		{
			// check if the right side has a function, if so, this is an input
			for (tree<AstNode>::iterator jter = tr.begin(iter); jter != tr.end(iter); ++jter) {
				string t = jter->getType();
				if (t == "function_call") {
					tree<AstNode>::iterator son = tr.begin(jter);
					if (son->getType() == "T_STRING") {
						tree<AstNode>::iterator  textable = tr.begin(son);
						if (textable->getType() == "text") {
							if (boxedSource.input.find(textable->getValue()) != boxedSource.input.end())
								continue;
							//cout << "Add in the boxed input ( "<< fctName << " ): " <<  textable->getValue() << endl;
							boxedSource.input.insert(make_pair(textable->getValue(), jter));
						}
					}
				}
				else if (t == "unticked_statement") {
					tree<AstNode>::iterator son = tr.begin(jter);
					if (utils::start_with(son->getType(), "T_")) {
						tree<AstNode>::iterator  textable = tr.begin(son);
						if (textable->getType() == "text") {
							if (boxedSource.input.find(textable->getValue()) != boxedSource.input.end())
								continue;
							//cout << "Add in the boxed input ( "<< fctName << " ): " <<  textable->getValue() << endl;
							boxedSource.input.insert(make_pair(textable->getValue(), jter));
						}
					}
				}
			}
		}
	}

	// Second pass to get the isolated calls, getting the output
	for (tree<AstNode>::iterator iter = tr.begin(it); iter != tr.end(it); ++iter) 
	{
		string t = iter->getType();
		if (t == "unticked_function_declaration_statement") {
			iter = tr.end(iter);
		}
		else if (t == "function_call") {
			tree<AstNode>::iterator son = tr.begin(iter);
			if (son->getType() == "T_STRING") {
				tree<AstNode>::iterator  textable = tr.begin(son);
				if (textable->getType() == "text") {
					if (boxedSource.output.find(textable->getValue()) != boxedSource.output.end())
						continue;
					//cout << "Add in the boxed output ( "<< fctName << " ): " <<  textable->getValue() << endl;
					boxedSource.output.insert(make_pair(textable->getValue(), iter));
				}
			}
		}
		else if (t == "unticked_statement") {
			tree<AstNode>::iterator son = tr.begin(iter);
			if (utils::start_with(son->getType(), "T_")) {
				tree<AstNode>::iterator  textable = tr.begin(son);
				if (textable->getType() == "text") {
					if (boxedSource.output.find(textable->getValue()) != boxedSource.output.end())
						continue;
					//cout << "Add in the boxed output ( "<< fctName << " ): " <<  textable->getValue() << endl;
					boxedSource.output.insert(make_pair(textable->getValue(), iter));
				}
			}
		}
	}
}

/**
	Boxing a function. Get inputs/outputs in term of functions.
*/
void Ast::functionBoxing(const tree<AstNode>::iterator& it, const std::string& fctName)
{
	if (boxedFunction.find(fctName) != boxedFunction.end())
		return;
	else
	{
		BoxedFunction bFct;
		// Get the input
		for (tree<AstNode>::iterator iter = tr.begin(it); iter != tr.end(it); ++iter)
		{
			if (detectAssignment(iter))
			{
				// check if the right side has a function, if so, this is an input
				for (tree<AstNode>::iterator jter = tr.begin(iter); jter != tr.end(iter); ++jter) {
					string t = jter->getType();
					if (t == "function_call") {
						tree<AstNode>::iterator son = tr.begin(jter);
						if (son->getType() == "T_STRING") {
							tree<AstNode>::iterator  textable = tr.begin(son);
							if (textable->getType() == "text") {
								if (bFct.input.find(textable->getValue()) != bFct.input.end())
									continue;
								//cout << "Add in the boxed input ( "<< fctName << " ): " <<  textable->getValue() << endl;
								bFct.input.insert(make_pair(textable->getValue(), jter));
							}
						}
					}
					else if (t == "unticked_statement") {
						tree<AstNode>::iterator son = tr.begin(jter);
						if (utils::start_with(son->getType(), "T_")) {
							tree<AstNode>::iterator  textable = tr.begin(son);
							if (textable->getType() == "text") {
								if (bFct.input.find(textable->getValue()) != bFct.input.end())
									continue;
								//cout << "Add in the boxed input ( "<< fctName << " ): " <<  textable->getValue() << endl;
								bFct.input.insert(make_pair(textable->getValue(), jter));
							}
						}
					}
				}
			}
		}
		// Second pass to get the isolated calls, getting the output
		for (tree<AstNode>::iterator iter = tr.begin(it); iter != tr.end(it); ++iter) 
		{
			string t = iter->getType();
			if (t == "function_call") {
				tree<AstNode>::iterator son = tr.begin(iter);
				if (son->getType() == "T_STRING") {
					tree<AstNode>::iterator  textable = tr.begin(son);
					if (textable->getType() == "text") {
						if (bFct.output.find(textable->getValue()) != bFct.output.end())
							continue;
						//cout << "Add in the boxed output ( "<< fctName << " ): " <<  textable->getValue() << endl;
						bFct.output.insert(make_pair(textable->getValue(), iter));
					}
				}
			}
			else if (t == "unticked_statement") {
				tree<AstNode>::iterator son = tr.begin(iter);
				if (utils::start_with(son->getType(), "T_")) {
					tree<AstNode>::iterator  textable = tr.begin(son);
					if (textable->getType() == "text") {
						if (bFct.output.find(textable->getValue()) != bFct.output.end())
							continue;
						//cout << "Add in the boxed output ( "<< fctName << " ): " <<  textable->getValue() << endl;
						bFct.output.insert(make_pair(textable->getValue(), iter));
					}
				}
			}
		}
		boxedFunction.insert(make_pair(fctName, bFct));
		//cout << "box size = " << boxedFunction.size() << endl;
	}
}

/**
	Mapping one function to others. The other functions are all the function call in
	the function.
*/
void Ast::functionMapping(const tree<AstNode>::iterator& it, const std::string& fctName)
{
	if (fctmap.find(fctName) != fctmap.end())
		return;
	else
	{
		list<string> related;
		for (tree<AstNode>::iterator iter = tr.begin(it); iter != tr.end(it); ++iter) {
			string t = iter->getType();
			if (t == "function_call") {
				tree<AstNode>::iterator son = tr.begin(iter);
				if (son->getType() == "T_STRING") {
					tree<AstNode>::iterator  textable = tr.begin(son);
					if (textable->getType() == "text") {
						related.push_back(textable->getValue());
					}
				}
			}
			else if (t == "unticked_statement") {
				tree<AstNode>::iterator son = tr.begin(iter);
				if (utils::start_with(son->getType(), "T_")) {
					tree<AstNode>::iterator  textable = tr.begin(son);
					if (textable->getType() == "text") {
						related.push_back(textable->getValue());
					}
				}
			}
		}
		// Insert into the fctmap
		fctmap.insert(make_pair(fctName, related));
	}
}


/**
	Get in post-order all the variables
*/
list<VarBase> Ast::getSubVariables(const tree<AstNode>::iterator& it) const
{
	list<VarBase> varBaseList;
	if (nbNestedVariables(it) < 1)
		return varBaseList;
	//cerr << "start:- getSubVars" << endl;
	string type;
	for (tree<AstNode>::iterator iter=tr.begin(it);iter!=tr.end(it) && iter!=tr.end();iter++)
	{
		type = iter->getType();
		//cout << "\t\t\t => type = " << type << endl;
		if (type == "reference_variable")
		{
			//cerr << "\tref_var ";
			unsigned nbchilds = tr.number_of_children(iter);
			//cerr << nbchilds << endl;
			if (nbchilds == 1) {
				//cout << '[' << iter->getType() << " -> " << tr.child(iter,0)->getType()  << ']' << endl;

				if (tr.child(iter, 0)->getType() == "compound_variable") {
					// single variables
					tree<AstNode>::iterator var = iter;
					for(;var->getType() != "text" && var != tr.end(it); ++var)
						;
					//cerr << setw(15) << "ref :- [" << var->getValue() << ',' << it;
					varBaseList.push_back(VarBase(var->getValue(), it));
					//cerr << " ]" << endl;
					iter = var;
				}
			}
			else if (nbchilds == 4) {
				// array ?
				tree<AstNode>::iterator array = tr.child(iter, 0);
				tree<AstNode>::iterator index = tr.child(iter, 2);
				for(;array->getType() != "text" && array != tr.end(it); ++array)
					;
				for(;index->getType() != "text" && index != tr.end(it); ++index)
					;
				//cerr << setw(15) << "array:- [" << array->getValue() << ',' << it << ',' << index->getValue();
				varBaseList.push_back(VarBase(array->getValue(), it, index->getValue()));
				//cerr << " ]" << endl;
				iter = index;
			}
		}
		else if (type == "expr_without_variable" || type == "encaps_var")
		{
			//cerr << "\texpr_wo_var ";
			unsigned nbchilds = tr.number_of_children(iter);
			//cerr << nbchilds << endl;
			for (unsigned c=0;c<nbchilds;++c)
			{
				list<VarBase> varBaseListTemp = getSubVariables(tr.child(iter, c));
				if (varBaseListTemp.size() > 0) {
					// merge the list
					for (list<VarBase>::const_iterator jter=varBaseListTemp.begin();jter!=varBaseListTemp.end();++jter) {
						if (find(varBaseList.begin(),varBaseList.end(),*jter) == varBaseList.end()) {
							//cout << *jter << endl;
							varBaseList.push_back(*jter);
						}
					}
				}
			}
			/*
			// go to the T_VARIABLE
			tree<AstNode>::iterator var = iter;
			for(;var->getType() != "T_VARIABLE" && var != tr.end(it) && var != tr.end(); ++var)
				;
			var = tr.child(var, 0);
			cerr << setw(15) << "expr:- [" << var->getValue() << ',' << it;
			varBaseList.push_back(VarBase(var->getValue(), it));
			cerr << " ]" << endl;
			//iter = var;
			*/
		}
		else if (type == "T_VARIABLE")
		{
			//cout << "TVariable" << endl;
			tree<AstNode>::iterator var = iter;
			for(;var->getType() != "text" && var != tr.end(it); ++var)
				;
			//cerr << setw(15) << "ref :- [" << var->getValue() << ',' << it;
			varBaseList.push_back(VarBase(var->getValue(), it));
			//cerr << " ]" << endl;
			iter = var;
		}
	}
	//cerr << "end:- getSubVars" << endl;
	return varBaseList;
}

/**
	Get in post-order the right variables assignments
*/
list<VarBase> Ast::getRightVariables(const tree<AstNode>::iterator& it, const VarBase& left)
{

	list<VarBase> varBaseList;
	unsigned nestedVars = nbNestedVariables(it);
	if (nestedVars == 0)
		return varBaseList;
	else if (nestedVars == 1 && !detectAssignment(it)) {
		VarBase simple = getSimpleVariable(it);
		varBaseList.push_back(simple);
		return varBaseList;
	}
	else
	{
		// Go to the last right 'expr_without_variable'
		unsigned nbchilds = tr.number_of_children(it);
		tree<AstNode>::iterator iter = tr.child(it, nbchilds - 1);
		//
		if (detectAssignment(iter)) {
			// Assignment => Let's move to the right, and grab the left variable as a 'left variable'
			VarBase leftVar = getLeftVariable(tr.child(iter, 0));
			if (leftVar.name != "")
				varBaseList.push_back(leftVar);
			list<VarBase> rightVars = getRightVariables(tr.child(iter, 2), left);
			// merge the result
			for (list<VarBase>::const_iterator jt=rightVars.begin(); jt!=rightVars.end();++jt)
				varBaseList.push_back(*jt);
		}
		else {
			AstVarBaseList locVarList;
			// get all variables, put that in a equivalences
			for (tree<AstNode>::iterator jter = iter;jter != tr.end(iter); ++jter) {
				string type(jter->getType());
				if (type == "reference_variable")
				{
					unsigned nbchilds = tr.number_of_children(jter);
					if (nbchilds == 1) {
						if (tr.child(jter, 0)->getType() == "compound_variable") {
							// single variables
							tree<AstNode>::iterator var = jter;
							for(;var->getType() != "text"; ++var)
								;
							//cerr << "I got this? " << var->getValue() << endl;
							VarBase right(var->getValue(), it);
							if (!(find(locVarList.begin(), locVarList.end(),right) != locVarList.end()))
								locVarList.push_back(right);
							jter = var;
						}
					}
					else if (nbchilds == 4) {
						// array ?
						tree<AstNode>::iterator array = tr.child(jter, 0);
						tree<AstNode>::iterator index = tr.child(jter, 2);
						for(;array->getType() != "text" && array != tr.end(); ++array)
							;
						for(;index->getType() != "text" && index != tr.end(); ++index)
							;
						VarBase right(array->getValue(), it, index->getValue());
						if (!(find(locVarList.begin(), locVarList.end(),right) != locVarList.end()))
							locVarList.push_back(right);
						jter = index;								
					}
				}
				else if (type == "expr_without_variable")
				{
					//cerr << "expr_wo_var ";
					unsigned nbchilds = tr.number_of_children(iter);
					//cerr << nbchilds << endl;
					for (unsigned c=0;c<nbchilds;++c)
					{
						list<VarBase> varBaseListTemp = getSubVariables(tr.child(iter, c));
						if (varBaseListTemp.size() > 0) {
							// merge the list
							for (list<VarBase>::const_iterator jter=varBaseListTemp.begin();jter!=varBaseListTemp.end();++jter) {
								if (find(locVarList.begin(),locVarList.end(),*jter) == locVarList.end())
									locVarList.push_back(*jter);
							}
						}
					}

				/*
					// go to the T_VARIABLE
					tree<AstNode>::iterator var = jter;
					for(;var->getType() != "T_VARIABLE"; ++var)
						;
					var = tr.child(var, 0);
					//cerr << "I got this? " << var->getValue() << endl;
					VarBase right(var->getValue(), it);
					if (!(find(locVarList.begin(), locVarList.end(),right) != locVarList.end()))
						locVarList.push_back(right);
				*/
				}
			}
			// local equivalences
			equivalences.insert(make_pair(left, locVarList));					
		}
		return varBaseList;
	}
}

/**
	Get a simple variable name; we know that there is one expression with one variable inside.
	We need to get this!
*/
VarBase Ast::getSimpleVariable(const tree<AstNode>::iterator& it)
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
					return VarBase(var->getValue(), it);
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
				return VarBase(array->getValue(), it, index->getValue());
			}
		}
		else if (iter->getType() == "expr_without_variable")
		{
			// go to the T_VARIABLE
			tree<AstNode>::iterator var = iter;
			for(;var->getType() != "T_VARIABLE"; ++var)
				;
			var = tr.child(var, 0);
			return VarBase (var->getValue(), it);
		}
	}
	// backtrack for: strings, functions, class
	return VarBase();
}

/**
	Get left variable name
*/
VarBase Ast::getLeftVariable(const tree<AstNode>::iterator& iter)
{
	tree<AstNode>::iterator it = iter;
	for (;it->getType() != "reference_variable"; ++it)
		;
	unsigned nbchilds = tr.number_of_children(it);
	if (nbchilds == 1) {
		tree<AstNode>::iterator var = it;
		for(;var->getType() != "text"; ++var)
			;
		return VarBase(var->getValue(), it);
	}
	else if (nbchilds == 4) {
		// $foo['var'] pattern detected!
		tree<AstNode>::iterator array = tr.child(it, 0);
		tree<AstNode>::iterator index = tr.child(it, 2);
		for(;array->getType() != "text" && array != tr.end(); ++array)
			;
		for(;index->getType() != "text" && index != tr.end(); ++index)
			;
		return VarBase(array->getValue(), it, index->getValue());
	}
	else {
		// Not supported
		cerr << "getLeftVariable, unsupported elemnts nb = " << *it << endl;
		return VarBase();
	}
	return VarBase();
}

void Ast::fillAstInformation()
{
	tree<AstNode>::iterator iter = tr.begin();
	sourceBoxing(iter);
	tree<AstNode>::sibling_iterator textable;
	tree<AstNode>::fixed_depth_iterator fter = iter;
	for (;iter != tr.end(); ++iter)
	{
		string type = iter->getType();
		if (type == "unticked_class_declaration_statement")
		{	
			string className = getChildValue(iter, "T_STRING");
			if (classes.find(className) != classes.end())
				continue;
			classes.insert(make_pair(className, iter));
		}
		else if (type == "unticked_function_declaration_statement")
		{
			string funcName = getChildValue(iter, "T_STRING");
			if (functions.find(funcName) != functions.end())
				continue;
			functions.insert(make_pair(funcName, iter));
			// Fill the function mapping win this function
			functionMapping(iter, funcName);
			// Get the boxed functions
			functionBoxing(iter, funcName);
		}
		// Variables Names detection
		else if (type == "reference_variable")
		{
			tree<AstNode>::iterator next = iter; ++next;
			if (next->getType() != "compound_variable") {
				// variable with array: $_GET['foo'] => $_GET, [, 'foo', ]
				tree<AstNode>::iterator array = tr.child(iter, 0);
				tree<AstNode>::iterator index = tr.child(iter, 2);
				for(;array->getType() != "text"; ++array)
					;
				for(;index->getType() != "text"; ++index)
					;
				VarBase var(array->getValue(), iter, index->getValue());
				if (!(variables.find(var.name) != variables.end())) {
					AstVarBaseList astFooIterList;
					variables.insert(make_pair(var.name, astFooIterList));
				}
				variables.find(var.name)->second.push_back(var);
			}
		}
		else if (type == "T_VARIABLE")
		{
			textable = tr.begin(iter);
			if (textable->getType() == "text") {
				VarBase var(textable->getValue(), iter);
				if (!(variables.find(var.name) != variables.end())) {
					AstVarBaseList astFooIterList;
					variables.insert(make_pair(var.name, astFooIterList));
				}
				variables.find(var.name)->second.push_back(var);
			}
		}
	}
	for (iter = tr.begin();iter != tr.end(); ++iter) {
		// Assignments, variables relation
		if (detectAssignment(iter))
		{
			VarBase leftVariable = getLeftVariable(tr.child(iter, 0));
			unsigned nbchilds = tr.number_of_children(iter);
			list<VarBase> rightVariables = getRightVariables(tr.child(iter, nbchilds - 1), leftVariable);
			// Store the information
			// for r in rights | reverse:
			//      add ( left <- r )
			//      add (    r <- r + 1 )
			list<VarBase>::reverse_iterator prev = rightVariables.rbegin();
			for (list<VarBase>::reverse_iterator i=rightVariables.rbegin(); i!=rightVariables.rend();++i) {
				// add the link with the left variables
				assign.insert(make_pair(leftVariable, *i));
				if (!(i == rightVariables.rbegin()))
					assign.insert(make_pair(*i, *prev));
				prev = i;
			}
			MapVarEquivalent::iterator rIter;
			for (rIter = equivalences.begin(); rIter != equivalences.end(); ++rIter)
				if (rIter->first == leftVariable) {
					//print_current_list(rIter->second);
				}
			// get the next same_depth iterator since I explored all the children
			tree<AstNode>::fixed_depth_iterator fter = iter;
			iter = ++fter;
		}
	}

}

void Ast::walk(xmlNode *a_node, tree<AstNode>::iterator parent)
{
	xmlNode *cur_node = 0;
	tree<AstNode>::iterator iter = parent;
	for (cur_node = a_node; cur_node; cur_node = cur_node->next) 
	{
		if (cur_node->type == XML_ELEMENT_NODE) {
			string name((char *)cur_node->name);
			iter = tr.append_child(parent,AstNode(name));
		}
		else if (cur_node->type == XML_TEXT_NODE) {
			string content = getContent(cur_node);
			string name((char *)cur_node->name);
			if (content.length() > 0) {
				iter = tr.append_child(parent, AstNode(name, content));
			}
		}
		walk(cur_node->children, iter);
	}
}

Ast::Ast(const string& xmlName)
{
	xmlDoc *doc = 0;
	xmlNode *root_element = 0;
#ifdef xmlReadFile
	doc = xmlReadFile(xmlName.c_str(), 0, 0);
#else
	doc = xmlParseFile(xmlName.c_str());
#endif
	if (doc == 0) {
		cerr << "error: could not parse file :" << xmlName << endl;
	}
	root_element = xmlDocGetRootElement(doc);
	root = tr.begin();
	root = tr.insert(root, AstNode("root"));
	walk(root_element, root);
	xmlFreeDoc(doc);
	xmlCleanupParser();
	fillAstInformation();
}

bool Ast::is_skeleton_node(const tree<AstNode>::iterator& it) const 
{
	string t = it->getType();
	if (t == "T_INLINE_HTML")
		return false;
	else if (t == "text") {
		// look at the parent, if it's T_VARIABLE or T_STRING, keep it
		tree<AstNode>::iterator parent = tr.parent(it);
		string pt = parent->getType();
		if (pt == "T_VARIABLE" || pt == "T_STRING" || pt == "T_CONSTANT_ENCAPSED_STRING")
			return true;
		return false;
	}
	else if ((t == "root" || t == "start" || t == "CHAR61" || t == "expr" || t == "top_statement_list"
	|| t == "internal_functions_in_yacc" || t == "function_call" || t == "statement" || t == "unticked_statement"
	|| utils::start_with(t, "T_")))
		return true;
	return false;
}

bool Ast::detectFunction(const tree<AstNode>::iterator& i) const {
	if (i->getType() == "function_call")
		return true;
	return false;
}


void Ast::trace(const std::string &varName) const
{
	// Find that variables
	AstVarBaseList obsVars, totalVars;
	MapVariables::const_iterator pos=variables.find(varName);
	if (pos != variables.end())
		obsVars = pos->second;
	// check with the assignments to see whether we should look for other variables
	totalVars = obsVars;
	for (MapAssignments::const_iterator iter=assign.begin();iter!=assign.end();++iter) 
	{
		for (AstVarBaseList::iterator jter=totalVars.begin();jter!=totalVars.end();++jter)
		{
			//cerr << "What about?" << iter->second << " , " << *jter << endl;
			if (iter->second.name == jter->name) {
				if (find(totalVars.begin(), totalVars.end(), iter->first) == totalVars.end())
					totalVars.push_back(iter->first);				
			}
		}
	}
	print_current_list(totalVars);
	// For each variable in the domain, look for the functions, calls etc.
	for (AstVarBaseList::iterator iter=totalVars.begin(); iter!=totalVars.end();++iter) {
		cerr << *iter << endl;
		// take this variable and rewind it!
		tree<AstNode>::iterator	nter = iter->position;
		do {
			nter = tr.parent(nter);
			// Check for functions
			if (detectFunction(nter)) {
				cerr << nter << endl;
			}
		} while (nter != tr.begin());			
	}
}

Ast Ast::skeleton() const
{
	Ast temp(*this);
	temp.ref = const_cast<Ast *>(this);
	for (tree<AstNode>::iterator iter=temp.tr.begin(); iter!=temp.tr.end();++iter)
	{
		if (!temp.is_skeleton_node(iter)) {
			// just delete it with reparent
			temp.tr.reparent(temp.tr.parent(iter), iter);
		}
	}
	return temp;	
}


void Ast::printInfo(ostream& stream) const
{
	stream << "-- Ast Information --" << endl;
	stream << "Functions:" << endl;
	for (MapFunctions::const_iterator iter = functions.begin(); iter != functions.end(); ++iter) {
		stream << '\t' << iter->first << '|' << iter->second->getType() << endl;
	}
	stream << "Classes:" << endl;
	for (MapClasses::const_iterator iter = classes.begin(); iter != classes.end(); ++iter) {
		stream << '\t' << iter->first << '|' << iter->second->getType() << endl;
	}
	stream << "Variables:" << endl;
	for (MapVariables::const_iterator iter = variables.begin(); iter != variables.end(); ++iter) {
		stream << setw(10) << iter->first << endl;
	}
	stream << "Assignments:" << endl;
	for (MapAssignments::const_iterator iter = assign.begin(); iter != assign.end(); ++iter) {
		stream << '\t' << iter->first << " <-- " << iter->second << endl;
	}
	
	stream << "Equivalences:" << endl;
	for (MapVarEquivalent::const_iterator iter = equivalences.begin(); iter != equivalences.end(); ++iter)
	{
		stream << setw(10) << iter->first << ": \t";
		for (AstVarBaseList::const_iterator jter=iter->second.begin(); jter!=iter->second.end();++jter)
			stream << *jter << ", ";
		stream << endl;
	}
}

void Ast::clearInfo()
{
	classes = MapClasses();
	variables = MapVariables();
	functions = MapFunctions();
}

string htmlentities(const string& str)
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

void writeSiblingsXML(const tree<AstNode>& t, const tree<AstNode>::iterator iRoot, ostream& stream)
{
	if(t.empty()) 
		return;
	if (iRoot->getType() == "root") {
		tree<AstNode>::sibling_iterator iChildren = t.begin(iRoot);
		stream << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>" << endl;
		writeSiblingsXML(t,iChildren,stream);
	}
	else if (t.number_of_children(iRoot) == 0) {
		string type = iRoot->getType();
		stream << "<php:" << type << '>';
		if (iRoot->getValue().length() > 0)
			stream << htmlentities(iRoot->getValue());
		stream << "</php:" << type << '>' << endl;
	}
	else {
		string type = iRoot->getType();
		string xmlns="";
		if (type == "start")
			xmlns = " xmlns:php=\"http://php.net/csl\"";
		stream << "<php:" << type << xmlns << '>' << endl;
		int siblingNum;
		tree<AstNode>::sibling_iterator iChildren;
		for (iChildren = t.begin(iRoot), siblingNum = 0; iChildren != t.end(iRoot); ++iChildren) 
		{
			writeSiblingsXML(t,iChildren,stream);
		}
		stream << "</php:" << type << '>' << endl;
	}
}

void exportXML(const Ast& ast, const string& xmlName)
{
	if (ast.tr.empty()) {
		throw length_error("AstContainer::exportXML - The AST is empty");
		return;
	}
	ofstream stream(xmlName.c_str());
	if (!stream.is_open())
		return;
	// skip <root>
	for(tree<AstNode>::sibling_iterator iRoots = ast.tr.begin(); iRoots != ast.tr.end(); iRoots++) {
		writeSiblingsXML(ast.tr,iRoots,stream);
	}
	stream.close();
}
