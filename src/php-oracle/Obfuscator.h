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

#ifndef __OBFUSCATOR_H
#define __OBFUSCATOR_H

#include <string>

/**
	Obfuscator algorithms abstract class
*/
class Obfuscator {
  public:
	Obfuscator() {}
	virtual ~Obfuscator() {}
  public:
	virtual void operator()(tree<AstNode>&, MapClasses* classes = 0, MapVariables* vars = 0, MapFunctions *func = 0) = 0;
};


class RenameClass : public Obfuscator
{
  public:
	virtual ~RenameClass() {}
	virtual void operator()(tree<AstNode>&, MapClasses* classes = 0, MapVariables* vars = 0, MapFunctions *func = 0);
};

class RenameFunction : public Obfuscator
{
  public:
	virtual ~RenameFunction() {}
	virtual void operator()(tree<AstNode>&, MapClasses* classes = 0, MapVariables* vars = 0, MapFunctions *func = 0);
};


class RenameVariable : public Obfuscator
{
  public:
	virtual ~RenameVariable() {}
	virtual void operator()(tree<AstNode>&, MapClasses* classes = 0, MapVariables* vars = 0, MapFunctions *func = 0);
};

class ControlFlow : public Obfuscator
{
  public:
	Ast flowAST;
  public:
	ControlFlow(){}
	ControlFlow(const std::string& flowXML) { 
		flowAST = Ast(flowXML);
	}
	virtual ~ControlFlow() {}
	virtual void operator()(tree<AstNode>&, MapClasses* classes = 0, MapVariables* vars = 0, MapFunctions *func = 0);
};


#endif
