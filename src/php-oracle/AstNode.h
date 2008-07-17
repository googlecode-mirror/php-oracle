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

#ifndef __AST_NODE_H
#define __AST_NODE_H

#include <string>

class AstNode
{
	std::string type;
	std::string value;
  public:
	AstNode(const std::string& _type = "", const std::string& _value = "")
	  : type(_type), value(_value) {}
	AstNode(const AstNode& n) {
		if (this != &n)
			*this = n;
	}
	~AstNode() {}
	
	AstNode& operator=(const AstNode& n) {
		if (this != &n) {
			type = n.type;
			value= n.value;
		}
		return *this;
	}
	
	bool operator==(const AstNode& n) const {
		return this == &n;
	}

	inline void setValue(const std::string& v) { value = v; }
	inline void setType(const std::string& t)  { type  = t; }
	std::string getValue() const { return value; }
	std::string getType() const  { return type; }
	
	friend std::ostream& operator<<(std::ostream& stream, const AstNode& node);
};

std::ostream& operator<<(std::ostream& stream, const AstNode& node);

#endif
