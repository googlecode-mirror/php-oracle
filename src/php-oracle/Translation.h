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

#ifndef __TRANSLATION_H
#define __TRANSLATION_H

#include <string>
#include <list>
#include <iostream>
#include "Utils.h"

class StringBuffer
{
	std::string buffer;
  public:
	StringBuffer(){}
	StringBuffer(const StringBuffer& s) { buffer = s.buffer; }
	StringBuffer(const std::string& _first) { buffer += (_first); }
	StringBuffer(const unsigned n) { buffer += (to_string<unsigned>(n)); }
	~StringBuffer(){}
	
	// Operators
	StringBuffer& operator=(const StringBuffer& b) {
		buffer = b.buffer;
		return *this;
	}
	StringBuffer& operator<<(const StringBuffer& s) {
		buffer += (s.buffer);
		return *this;
	}
	StringBuffer& operator<<(const std::string& s) {
		buffer += (s);
		return *this;
	}
	void endl() { buffer += "\n"; }
	void replace(const std::string& what, const std::string& with) {
		utils::replace(buffer, what, with);
	}
	void insert_begin(const StringBuffer& s) {
		std::string out = s.buffer + buffer;
		buffer = out;
	}
	void format();
	void write(const std::string& _fname);
	// Print
	friend std::ostream& operator<<(std::ostream& stream, const StringBuffer&);
};

std::ostream& operator<<(std::ostream&, const StringBuffer&);

class Translation
{
  public:
	Translation() {}
	virtual ~Translation() {}
  public:
	virtual StringBuffer operator()(const tree<AstNode>&, const MapClasses* classes = 0, const MapVariables* vars = 0, 
	                                const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0) = 0;
};


class Ast2Cpp : public Translation
{
  public:
	Ast2Cpp() {}
	virtual ~Ast2Cpp() {}
  public:
	virtual StringBuffer operator()(const tree<AstNode>&, const MapClasses* classes = 0, const MapVariables* vars = 0, 
	                                const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0);
};

class Ast2Php : public Translation
{
  public:
	Ast2Php() {}
	virtual ~Ast2Php() {}
  public:
	virtual StringBuffer operator()(const tree<AstNode>&, const MapClasses* classes = 0, const MapVariables* vars = 0, 
	                                const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0);
};



#endif
