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

#ifndef __AST_CONTAINER_H
#define __AST_CONTAINER_H

#include "tree.h"
#include "tree_util.h"
#include "AstNode.h"
#include "AstPath.h"
#include "AstRange.h"
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

//! Simple Variable declaration using the position in the tree
class VarBase {
  public:
	std::string name;
	tree<AstNode>::iterator position;
	std::string index;
  public:
	VarBase() {}
	VarBase(const std::string& _name, const tree<AstNode>::iterator& _pos, const std::string& _index = "")
	 : name(_name), position(_pos), index(_index) {}
	VarBase(const VarBase& v) : name(v.name), position(v.position), index(v.index) {}	
	VarBase& operator=(const VarBase& v) {
		if (this != &v) {
			name = v.name; position = v.position; index = v.index;
		}
		return *this;	
	}
	~VarBase() {}
	bool operator==(const VarBase& v) const {
		if (v.name != name || v.index != index || v.position != position)
			return false;
		return true;
	}
};

struct VarBaseCmp {
	bool operator()(const VarBase& v1, const VarBase& v2) const {
		if (v1.name != v2.name)
			return v1.name <= v2.name;
		else
			return v1.index > v2.index;
		return false;
	}
};



class MetricResult;
class Metric;
class Obfuscator;
class Translation;
class StringBuffer;

typedef std::list<VarBase> AstVarBaseList;
typedef std::list<tree<AstNode>::iterator > AstNodeIteratorList;
typedef std::multimap<VarBase, VarBase, VarBaseCmp> MapAssignments;
typedef std::map<VarBase, AstVarBaseList, VarBaseCmp> MapVarEquivalent;
typedef std::map<std::string, AstVarBaseList>  MapVariables;
typedef std::map<std::string, tree<AstNode>::iterator > MapFunctions;
typedef std::map<std::string, tree<AstNode>::iterator > MapClasses;
typedef std::map<std::string, std::list<std::string> > FunctionMapping; // one function to many

/**
	BoxedFunction modelize a function as a series of input and output:
	 - input : the function called inside the functions are inputs to something (variable, etc.)
	              ex -- foo = sql(query) in a function, 'sql' is an input
	- output : the function is actually returning as output something (transformation of variables)
*/
struct BoxedFunction {
	//! input: variable = function(...)
	MapFunctions input;
	//! output: function(variable)
	MapFunctions output;
	// Class Prototype
	BoxedFunction() {}
	BoxedFunction(const BoxedFunction& b) : input(b.input), output(b.output) {}
	BoxedFunction& operator=(const BoxedFunction& b) {
		input = b.input;
		output = b.output;
		return *this;
	}
	~BoxedFunction() {}

	inline bool isInput(const std::string& __str) {
		return input.find(__str) != input.end();
	}
	inline bool isOutput(const std::string& __str) {
		return output.find(__str) != output.end();
	}
};


/**
	The Ast class is the main container of the AST.
	It contains all possible information about the source code: variable names (context), function, etc.
*/
class Ast
{
  protected:
	//! Store the tree
	tree<AstNode> tr;
	//! Iterator to the root of the tree
	tree<AstNode>::iterator root;
	//! Function name to tree iterator
	MapFunctions functions;
	//! Variable name to list of variable (VarBase) which depends on the context of the variable
	MapVariables variables;
	//! Class name to tree iterator
	MapClasses   classes;
	//! Relations within variables (contexted)
	MapAssignments assign;
	//! For the assignments, I need an equivalence between some variables $a = foo($b,$c,$d) with foo as a black box
	//! then, the variables b,c,d are equivalent given that $a variable
	MapVarEquivalent equivalences;
	//! For one function, list of what function is used as input and what is used as output
	std::map<std::string, BoxedFunction> boxedFunction;
	//! Function to list of function used in
	FunctionMapping fctmap;
	//! Reference to another tree, used for in-skeleton transformation
	Ast *ref;
	//! Do a boxing of the current source code, this is helpful for non function based code (php,asp, etc.)
	BoxedFunction boxedSource;

  private:
	//! Walk into the XML tree in order to build the AST in-memory
	void walk(xmlNode *a_node, tree<AstNode>::iterator parent);

  protected:
	//! Check whether the current node is a "skeleton node" or not
	//! A skeleton tree is a simplified one, derived from the AST
	bool is_skeleton_node(const tree<AstNode>::iterator& ) const;

	//! Scan the tree to fill the information about variables, functions etc.
	void fillAstInformation();
	
	//! Clear all information
	void clearInfo();
	
	//! Going down one node, return the name of the value (may be function, class, variable, etc.)
	std::string getChildValue(tree<AstNode>::iterator parent, const std::string& nodeName = "T_STRING") const;
	
	//! Return the number of nested variables: the number of variable in the sub-tree
	unsigned nbNestedVariables(const tree<AstNode>::iterator& iter) const;

	//! Get all the function names used in a function or method
	void functionMapping(const tree<AstNode>::iterator& it, const std::string& fctName);
	
	//! Box one function
	void functionBoxing(const tree<AstNode>::iterator& it, const std::string& fctName);

	//! Source boxing
	void sourceBoxing(const tree<AstNode>::iterator& it);

  protected:
	//! Detect if there is an assignment in the subtree
	bool detectAssignment(const tree<AstNode>::iterator& it) const;

	//! Detect if there is a function declaration in the subtree
	bool detectFunction(const tree<AstNode>::iterator& i) const;

	//! Must not be 'const' since it can write to the MapAssignements...
	std::list<VarBase> getRightVariables(const tree<AstNode>::iterator& it, const VarBase& left);

	//! Get the variable in the left of an assignment
	VarBase getLeftVariable(const tree<AstNode>::iterator& it);

	//! Simply get the one variable with is on the subtree
	VarBase getSimpleVariable(const tree<AstNode>::iterator& iter);

  public:
  	//! Get the list of all subvariable
	std::list<VarBase> getSubVariables(const tree<AstNode>::iterator& it) const;

  public:
	// Full copelien class
	Ast() : root(tr.begin()) { ref = 0;}
	Ast(const Ast& ast) {*this = ast;}
	Ast(const std::string& xmlFile);
	Ast& operator=(const Ast& ast) {
		if (this != &ast) {
			tr = ast.tr;
			root = ast.root;
			functions = ast.functions;
			variables = ast.variables;
			classes   = ast.classes;
			equivalences = ast.equivalences;
			assign = ast.assign;
			ref = ast.ref;
		}
		return *this;	
	}
	~Ast() {}
	// Access
	tree<AstNode>* getTreePtr() { return (&tr); }
	const tree<AstNode>* getTreeConstPtr() const { return (const tree<AstNode>*)(&tr); }
	
	inline std::map<std::string, BoxedFunction> getBoxedFunctions() const {
		return boxedFunction;
	}
	inline FunctionMapping getMappedFunctions() const {
		return fctmap;
	}
	//! Get names informations
	inline std::list<std::string> getVariableNames() const {
		// extract the keys of the map 'variables'
		std::list<std::string> ret;
		for(MapVariables::const_iterator iter = variables.begin(); iter != variables.end(); ++iter)
			ret.push_back(iter->first);
		return ret;
	}
	inline std::list<std::string> getFunctionNames() const {
		std::list<std::string> ret;
		for(MapFunctions::const_iterator iter = functions.begin(); iter != functions.end(); ++iter)
			ret.push_back(iter->first);
		return ret;
	}
	inline std::list<std::string> getClassNames() const {
		std::list<std::string> ret;
		for(MapClasses::const_iterator iter = classes.begin(); iter != classes.end(); ++iter)
			ret.push_back(iter->first);
		return ret;
	}

	// Algorithms
	Ast skeleton() const;
	void trace(const std::string &varName) const;

	// Apply algorithms
	void apply  (Obfuscator* obs);
	StringBuffer convert(Translation* obs);

	MetricResult compute(Metric *metric) const;
	// Some functions...
	void printInfo(std::ostream& stream) const;
	// External functions
	friend std::ostream& operator<<(std::ostream& stream, const Ast& ast);
	friend void exportXML(const Ast& ast, const std::string& xmlName);
};


std::ostream& operator<<(std::ostream& stream, const tree<AstNode>& ast);
std::ostream& operator<<(std::ostream& stream, const Ast& ast);
std::ostream& operator<<(std::ostream& stream, const VarBase& v);
std::ostream& operator<<(std::ostream& stream, const tree<AstNode>::iterator& iter);
void exportXML(const Ast& ast, const std::string& xmlName);

#endif
