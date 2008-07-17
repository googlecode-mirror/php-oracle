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

#ifndef __SECURITY_H
#define __SECURITY_H

#include <map>
#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include "Utils.h"


struct SecurityAnalysisToken {
	/**
		Severity rating
		5: Critical: High & Simply exploitable
		4: High
		3: Medium
		2: Low
		1: Plop
		0: Information
	*/
	unsigned int severity;
	//! accuracy of the engine
	float probability;
	//! vulnerability type
	std::string type;

	//! path
	std::list<AstNode *> path;

	~SecurityAnalysisToken() {}
	SecurityAnalysisToken() {}
	SecurityAnalysisToken(const SecurityAnalysisToken& s) {
		severity = s.severity;
		probability = s.probability;
		type = s.type;
		path = s.type;
	}
	SecurityAnalysisToken& operator=(const SecurityAnalysisToken& s) {
		severity = s.severity;
		probability = s.probability;
		type = s.type;
		path = s.type;
	}
};


typedef std::list<SecurityAnalysisToken> SecurityAnalysisResult;


/**
	Security Analyzer abstract class
*/
class Security {
  public:
	Security() {}
	virtual ~Security() {}
  public:
	virtual SecurityAnalysis operator()(const tree<AstNode>& tr, const MapClasses* classes = 0, const MapVariables* vars = 0,
	                                    const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0) = 0;
};


/**
	Analyze the technical flaws such as XSS, SQL Injection, etc.
*/
class FlawsAnalyzer : public Security
{
  public:
	Ast defAST;
  	const Ast *ast;
	std::list<std::string> sensitive;
	std::list<std::string> sanitize;
	std::list<std::string> tainted;
  public:
	FlawAnalyzer(){}
	FlawAnalyzer(const Ast* astPtr, const std::string& defASTStr, const std::list<std::string>& sinks, 
	             const std::list<std::string>& sanit,const std::list<std::string>& tSrc,) {
		ast = astPtr;
		defAST = Ast(defASTStr);
		sensitive = sinks;
		sanitize  = sanit;
		tainted   = tSrc;
	}
	virtual ~FlawAnalyzer() {}
	virtual SecurityAnalysis operator()(const tree<AstNode>&, const MapClasses* classes = 0, const MapVariables* vars = 0,
	                                    const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0);
};


#endif
