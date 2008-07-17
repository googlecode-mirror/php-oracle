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

#ifndef __METRIC_H
#define __METRIC_H

#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include "Utils.h"


class NumericResult 
{
	std::string container;
  public:
	NumericResult(){}
	NumericResult(int c) { container = to_string<int>(c); }
	NumericResult(float c) { container = to_string<float>(c); }
	NumericResult(long c) { container = to_string<long>(c); }
	NumericResult(unsigned c) { container = to_string<unsigned>(c); }
	NumericResult(double c) { container = to_string<double>(c); }
	NumericResult(const std::string& c) {container=c;}
	
	NumericResult(const NumericResult& n) : container(n.container){}
		
	NumericResult& operator=(const NumericResult& n) { container = n.container; return *this; }
	NumericResult& operator=(const int n) { container = to_string<int>(n); return *this; }
	NumericResult& operator=(const unsigned n) { container = to_string<unsigned>(n); return *this; }
	NumericResult& operator=(const long n) { container = to_string<long>(n); return *this; }
	NumericResult& operator=(const float n) { container = to_string<float>(n); return *this; }
	NumericResult& operator=(const double n) { container = to_string<double>(n); return *this; }	
	
	inline int toInt() const {
		int ret = 0;
		from_string<int>(ret,container);
		return ret;
	}
	inline float toFloat() const {
		float ret = 0;
		from_string<float>(ret,container);
		return ret;
	}
	inline long toLong() const {
		long ret = 0;
		from_string<long>(ret,container);
		return ret;
	}
	inline unsigned toUnsigned() const {
		unsigned ret = 0;
		from_string<unsigned>(ret,container);
		return ret;
	}
	inline double toDouble() const {
		double ret = 0;
		from_string<double>(ret,container);
		return ret;
	}
	inline std::string toString() const {
		return container;
	}
};



struct MetricResult
{
	NumericResult main;
	std::map<std::string, NumericResult> storage;
};


std::ostream& operator<<(std::ostream& stream, const NumericResult&);
std::ostream& operator<<(std::ostream& stream, const MetricResult&);



/**
	Metrics abstract class
*/
class Metric {
  public:
	Metric() {}
	virtual ~Metric() {}
  public:
	virtual MetricResult operator()(const tree<AstNode>&, const MapClasses* classes = 0, const MapVariables* vars = 0, 
	                                const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0) = 0;
};

class NumberFunctions : public Metric
{
  public:
	virtual ~NumberFunctions() {}
	virtual MetricResult operator()(const tree<AstNode>&, const MapClasses* classes = 0, const MapVariables* vars = 0, 
	                                const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0);
};


class NumberSinks : public Metric
{
  public:
	std::list<std::string> sensitive;
	const Ast* ast;
  public:
	NumberSinks(){}
	NumberSinks(const std::list<std::string>& sinks, const Ast* _ast = 0) {
		sensitive = sinks;
		ast = _ast;
	}
	virtual ~NumberSinks() {}
	virtual MetricResult operator()(const tree<AstNode>&, const MapClasses* classes = 0, const MapVariables* vars = 0,
	                                const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0);
};


class NumberResources : public Metric
{
  public:
	std::list<std::string> taintedinput;
	const Ast* ast;
  public:
	NumberResources(){}
	NumberResources(const std::list<std::string>& sinks, const Ast* _ast = 0) {
		taintedinput = sinks;
		ast = _ast;
	}
	virtual ~NumberResources() {}
	virtual MetricResult operator()(const tree<AstNode>&, const MapClasses* classes = 0, const MapVariables* vars = 0,
	                                const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0);
};



class NumberVariables : public Metric
{
  public:
	virtual ~NumberVariables() {}
	virtual MetricResult operator()(const tree<AstNode>&, const MapClasses* classes = 0, const MapVariables* vars = 0, 
	                                const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0);
};



class NumberClasses : public Metric
{
  public:
	virtual ~NumberClasses() {}
	virtual MetricResult operator()(const tree<AstNode>&, const MapClasses* classes = 0, const MapVariables* vars = 0, 
	                                const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0);
};


class NumberInput : public Metric
{
  public:
	Ast defAST;
  public:
	NumberInput(){}
	NumberInput(const std::string& defASTStr) {
		defAST = Ast(defASTStr);
	}
	virtual ~NumberInput() {}
	virtual MetricResult operator()(const tree<AstNode>&, const MapClasses* classes = 0, const MapVariables* vars = 0, 
	                                const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0);
};

class NumberDiffuseInputs : public Metric
{
  public:
	Ast defAST;
  public:
	NumberDiffuseInputs(){}
	NumberDiffuseInputs(const std::string& defASTStr) {
		defAST = Ast(defASTStr);
	}
	virtual ~NumberDiffuseInputs() {}
	virtual MetricResult operator()(const tree<AstNode>&, const MapClasses* classes = 0, const MapVariables* vars = 0, 
	                                const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0);
};

class NumberSunkDiffuseInputs : public Metric
{
  public:
	Ast defAST;
  	const Ast *ast;
	std::list<std::string> sensitive;
  public:
	NumberSunkDiffuseInputs(){}
	NumberSunkDiffuseInputs(const Ast* astPtr, const std::string& defASTStr, const std::list<std::string>& sinks) {
		defAST = Ast(defASTStr);
		sensitive = sinks;
		ast = astPtr;
	}
	virtual ~NumberSunkDiffuseInputs() {}
	virtual MetricResult operator()(const tree<AstNode>&, const MapClasses* classes = 0, const MapVariables* vars = 0, 
	                                const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0);
};






#endif
