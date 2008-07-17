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
#include "Obfuscator.h"
#include "Utils.h"
#include <cstdlib>
#include <string>
#include <map>
#include <iostream>
using namespace std;

const unsigned length = 16;

/**
	Generate a randome name
*/
string generateName() {
	static const string ref = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static const unsigned refL = ref.length();
	string ret;
#ifndef srand48
	#define srand48 srand
	#define lrand48 rand
#endif
	srand48(time(NULL) + lrand48() % 65527);
	ret += ref[((lrand48() % (refL-36))) + 36];
	for (unsigned i=1; i < length; i++)	{
		ret += ref[((lrand48() % refL))];
	}
	return ret;
}


/**
	Apply some modification to the current tree.
	This is used to load the external definition and change some names
*/
void applyModification(Ast& ast) {
	tree<AstNode> *tr = ast.getTreePtr();
	map<string, string> randNames;
	string randName = "";
	string randFunc = "";
	for (tree<AstNode>::iterator iter=tr->begin(); iter!=tr->end(); ++iter)	{
		string valueType = iter->getValue();
		if (utils::start_with(valueType,"$rand_name")
		||  utils::start_with(valueType,"rand_func_name")
		||  utils::start_with(valueType,"rand_class_name")) {
			string genValue = generateName();
			if (valueType[0] == '$')
				genValue = "$" + genValue;
			if (randNames.find(valueType) == randNames.end())
				randNames.insert(make_pair(valueType, genValue));
			iter->setValue(randNames[valueType]);
		}
		else if (utils::start_with(valueType,"$param_")) {
			string name = valueType;
			utils::replace(name, "param_","");
			iter->setValue(name);
		}
	}
}

/**
	Apply some modification to the current tree.
	This is used to load the external definition and change some names
*/
void applyModification(tree<AstNode>& tr) {
	map<string, string> randNames;
	string randName = "";
	string randFunc = "";
	for (tree<AstNode>::iterator iter=tr.begin(); iter!=tr.end(); ++iter)	{
		string valueType = iter->getValue();
		if (utils::start_with(valueType,"$rand_name")
		||  utils::start_with(valueType,"rand_func_name")
		||  utils::start_with(valueType,"rand_class_name")) {
			string genValue = generateName();
			if (valueType[0] == '$')
				genValue = "$" + genValue;
			if (randNames.find(valueType) == randNames.end())
				randNames.insert(make_pair(valueType, genValue));
			iter->setValue(randNames[valueType]);
		}
		else if (utils::start_with(valueType,"$param_")) {
			string name = valueType;
			utils::replace(name, "param_","");
			iter->setValue(name);
		}
	}
}



/**
	Insert all sub-jt into the sub-it
*/
void insert_branch(tree<AstNode>::iterator where, tree<AstNode>::iterator from, 
                   tree<AstNode>& tr_where, const tree<AstNode>& tr_from)
{
	if (tr_from.number_of_children(from) == 0) {
		// simply add the node to it
		tr_where.append_child(where, *from);
	}
	else {
		where = tr_where.append_child(where, *from);
		tree<AstNode>::sibling_iterator cter;
		for (cter = tr_from.begin(from); cter != tr_from.end(from); ++cter) 
		{
			insert_branch(where, cter, tr_where, tr_from);
		}
	}
}

/**
	Copy for duplicating a branch
*/
void copy_branch(tree<AstNode>::iterator where, tree<AstNode>::iterator from,  tree<AstNode>& tr_where)
{
	if (tr_where.number_of_children(from) == 0) {
		// simply add the node to it
		tr_where.append_child(where, *from);
	}
	else {
		where = tr_where.append_child(where, *from);
		tree<AstNode>::sibling_iterator cter;
		for (cter = tr_where.begin(from); cter != tr_where.end(from); ++cter) {
			copy_branch(where, cter, tr_where);
		}
	}
}

/**
	Move all the branches from 'from' to 'where' on the tree 'tr_where'
*/
void move_branch(const tree<AstNode>::iterator& where, const tree<AstNode>::iterator& from, tree<AstNode>& tr_where)
{
	copy_branch(where, from, tr_where);
	tr_where.erase(from);
}

/**
	Rewind in a tree until the value
*/
tree<AstNode>::iterator rewind(const tree<AstNode>::iterator& from, const string& untilStr, const tree<AstNode>& tr) {
	tree<AstNode>::iterator ret = from;
	while(ret->getType() != untilStr) { 
		ret = tr.parent(ret);
	}
	return ret;
}

/**
	Forward in a tree until the value
*/
tree<AstNode>::iterator forward(const tree<AstNode>::iterator& from, const string& untilStr, const tree<AstNode>& tr) {
	tree<AstNode>::iterator ret = from;
	while(ret->getType() != untilStr) { 
		ret = tr.child(ret, 0);
	}
	return ret;
}


/**
	Clean the possible patterns annotations:
		$enter_new_statement ...
*/
void clean_pattern(tree<AstNode>& tr) {
	for (tree<AstNode>::iterator iter=tr.begin(); iter!=tr.end(); ++iter) {
		if (iter->getType() == "text" && iter->getValue() == "$enter_the_new_statement") {
			iter = rewind(iter, "statement", tr);
			tr.erase(iter);
			break;
		}
	}
}


/**
	Insert a new statement.
	- Create a new inner_statement_list
	- Add the statement under it
*/
bool insert_statement(const tree<AstNode>::iterator& where, const tree<AstNode>::iterator& what, tree<AstNode>& tr)
{
	if (where->getType() == "text" && where->getValue() == "$enter_the_new_statement") {
		// rewind to the inner_statement_list
		tree<AstNode>::iterator top = where;
		do {
			top = tr.parent(top);
		} while (top->getType() != "inner_statement" && tr.child(top,0)->getType() != "statement");
		top = tr.parent(top);
		if (top->getType() != "inner_statement_list")
			return false;
		else {
			top = tr.append_child(top, AstNode("inner_statement_list"));
			top = tr.append_child(top, AstNode("inner_statement"));
			if (what->getType() == "statement") {
				top = tr.append_child(top, AstNode("statement"));
				//cout << "Seems to be okay..." << endl;
				move_branch(top, what, tr);
			}
		}
		return true;
	}
	return false;
}


void RenameClass::operator()(tree<AstNode>& tr, MapClasses* classes, MapVariables* vars, MapFunctions *func) {
	// for every names in the class, generate a new *unique* name
	map<string, string> classNames;
	for (MapClasses::iterator iter = classes->begin(); iter != classes->end(); ++iter)
	{
		string newName = generateName();
		classNames.insert(make_pair(iter->first, newName));		
	}
	map<string, string>::iterator cter;
	tree<AstNode>::iterator parent;
	for (tree<AstNode>::iterator iter=tr.begin(); iter!=tr.end(); ++iter)
	{
		parent = tr.parent(iter);
		if (iter->getType() == "text" 
			&& parent->getType() == "T_STRING"
			&& (tr.parent(parent)->getType() == "unticked_class_declaration_statement"
		       || tr.parent(parent)->getType() == "function_call" // constructor
			   || tr.parent(parent)->getType() == "class_name_reference"
			   || tr.parent(parent)->getType() == "fully_qualified_class_name"
			   )
			&& ((cter=classNames.find(iter->getValue())) != classNames.end())) {
			// rename the currenet node
			iter->setValue(cter->second);
		}			
	}		
}


void RenameFunction::operator()(tree<AstNode>& tr, MapClasses* classes, MapVariables* vars, MapFunctions *func) {
	// for every names in the class, generate a new *unique* name
	map<string, string> funcNames;
	for (MapFunctions::iterator iter = func->begin(); iter != func->end(); ++iter)
	{
		string newName = generateName();
		funcNames.insert(make_pair(iter->first, newName));		
	}
	map<string, string>::iterator cter;
	tree<AstNode>::iterator parent;
	for (tree<AstNode>::iterator iter=tr.begin(); iter!=tr.end(); ++iter)
	{
		parent = tr.parent(iter);
		if (iter->getType() == "text" 
			&& parent->getType() == "T_STRING" 
			&& (tr.parent(parent)->getType() == "unticked_function_declaration_statement" 
		        || tr.parent(parent)->getType() == "function_call")
			&& ((cter=funcNames.find(iter->getValue())) != funcNames.end())) {
			// rename the currenet node
			iter->setValue(cter->second);
		}			
	}		
}


void RenameVariable::operator()(tree<AstNode>& tr, MapClasses* classes, MapVariables* vars, MapFunctions *func) {

	// for every names in the class, generate a new *unique* name
	map<string, string> varNames;
	for (MapVariables::iterator iter = vars->begin(); iter != vars->end(); ++iter)
	{
		string newName = "$" + generateName();
		varNames.insert(make_pair(iter->first, newName));		
	}
	map<string, string>::iterator cter;
	for (tree<AstNode>::iterator iter=tr.begin(); iter!=tr.end(); ++iter)
	{
		if (iter->getType() == "text" && ((cter=varNames.find(iter->getValue())) != varNames.end())) {
			// rename the currenet node
			iter->setValue(cter->second);
		}			
	}		
}


bool detectBeforeStmt(const tree<AstNode>& tr) {
	unsigned short ret = 0;
	for (tree<AstNode>::iterator iter=tr.begin(); iter!=tr.end(); ++iter) {
		if (iter->getType() == "text" && iter->getValue() == "$__START_OBF_HERE") {
			return true;
		}
	}
	return false;
}

bool detectAfterStmt(const tree<AstNode>& tr) {
	unsigned short ret = 0;
	for (tree<AstNode>::iterator iter=tr.begin(); iter!=tr.end(); ++iter) {
		if (iter->getType() == "text" && iter->getValue() == "$__END_OBF_HERE") {
			return true;
		}
	}
	return false;
}

/**
	Generic control flow modification
*/
void ControlFlow::operator()(tree<AstNode>& tr, MapClasses* classes, MapVariables* vars, MapFunctions *func) {

	// 1 - Detect which if modifiying (select all the unticked_statement grand children of top_statement)
	AstNodeIteratorList affectedNode, untouchedBeforeNode, untouchedAfterNode;
	bool after  = detectAfterStmt(tr);
	bool before = detectBeforeStmt(tr);
	tree<AstNode>::iterator endStatement;	
	tree<AstNode> def = *(flowAST.getTreeConstPtr());
	

	tree<AstNode>::iterator iter, parent, grandparent;	
	if (!after && !before) {
		for (iter=tr.begin(); iter!=tr.end();++iter) {
			if (iter->getType() == "statement"
			&& tr.parent(iter)->getType() == "top_statement")
			{
				// We put the parent =? 'statement' in the list
				affectedNode.push_back(iter);
			}
		}
	}
	else {
		// feed the untouched and affected
		AstNodeIteratorList* curList = before ? &untouchedBeforeNode : &affectedNode;

		for (iter=tr.begin(); iter!=tr.end();++iter) {
			if (iter->getType() == "statement" && tr.parent(iter)->getType() == "top_statement")
				curList->push_back(iter);
			else if (before && iter->getType() == "text" && iter->getValue() == "$__START_OBF_HERE") {
				// remove the previously inserted stuff (the branch with this declaration
				curList->pop_back();			
			
				curList = &affectedNode;
				// rewind in order to include this variable into the generated obfuscated ast
				endStatement = iter;
				do { 
					endStatement = def.parent(endStatement);
				} while (endStatement->getType() != "statement" && def.parent(endStatement)->getType() != "top_statement");	
				curList->push_back(endStatement);
			}
			else if (after  && iter->getType() == "text" && iter->getValue() == "$__END_OBF_HERE")
				curList = &untouchedAfterNode;
		}
	}

	// 2 - Let's study a little out resource...
	AstNodeIteratorList branchs;
	AstNodeIteratorList br_func;
	AstNodeIteratorList br_classe;



	// 2+3/4 - Cut the external resource to implant it into the tree (get the nodes into the flowAST)
	for (tree<AstNode>::iterator iter=def.begin(); iter!=def.end(); ++iter)
	{
		if (iter->getValue() == "$enter_the_new_statement") {
			endStatement = iter;
			// rewind to the statement, not interesting by everything after this statement
			do { 
				endStatement = def.parent(endStatement);
			} while (endStatement->getType() != "statement" && def.parent(endStatement)->getType() != "inner_statement");
		}
		else if (iter->getType() == "top_statement") {
			if (tr.child(iter,0)->getType() == "function_declaration_statement")
				br_func.push_back(iter);
			else if (tr.child(iter,0)->getType() == "class_declaration_statement")
				br_classe.push_back(iter);
			else
				branchs.push_back(iter);
		}
	}
	//
	// 3 - Adding the nodes: merging the two trees
	tree<AstNode>::iterator topDeclarations = tr.begin();
	
	for (;topDeclarations!= tr.end(); ++topDeclarations) {
		if (topDeclarations->getType() == "top_statement_list")	{
			for (tree<AstNode>::iterator tmp=topDeclarations;tmp->getType()=="top_statement_list";++tmp)
				topDeclarations = tmp;
			break;
		}
	}

	// Insert the classes
	for (AstNodeIteratorList::iterator bter=br_classe.begin();bter!=br_classe.end();++bter)
		insert_branch(topDeclarations, *bter, tr, *(flowAST.getTreeConstPtr()));
	
	// Insert the functions
	for (AstNodeIteratorList::iterator bter=br_func.begin();bter!=br_func.end();++bter)
		insert_branch(topDeclarations, *bter, tr, *(flowAST.getTreeConstPtr()));

	// 
	if (before && untouchedBeforeNode.size() > 0) {
		for (AstNodeIteratorList::iterator bter=untouchedBeforeNode.begin();bter!=untouchedBeforeNode.end();++bter)
			insert_branch(topDeclarations, *bter, tr, *(flowAST.getTreeConstPtr()));
	}
	
	// Insert the obfuscation template (empty)
	for (AstNodeIteratorList::iterator bter=branchs.begin();bter!=branchs.end();++bter)
		insert_branch(topDeclarations, *bter, tr, *(flowAST.getTreeConstPtr()));

	//Select the place to insert
	for (tree<AstNode>::iterator iter=tr.begin();iter!=tr.end();++iter) {
		if (iter->getType() == "text" && iter->getValue() == "$enter_the_new_statement") {
			// Let's Insert Here!!
			for (AstNodeIteratorList::iterator jter=affectedNode.begin(); jter!=affectedNode.end();++jter) {
				insert_statement(iter, *jter ,tr);
			}
		}
	}
	// 
	if (after && untouchedAfterNode.size() > 0) {
		for (AstNodeIteratorList::iterator bter=untouchedAfterNode.begin();bter!=untouchedAfterNode.end();++bter)
			insert_branch(topDeclarations, *bter, tr, *(flowAST.getTreeConstPtr()));
	}

	// generate random names the remove the '$enter_the_new_statement'
	applyModification(tr);	
	clean_pattern(tr);
}
