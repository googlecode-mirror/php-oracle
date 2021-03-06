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

#ifndef __ABSTRACT_VISITOR_H
#define __ABSTRACT_VISITOR_H


/**
	Abstract Visitor class
*/
class AbstractVisitor {
  public:
	AbstractVisitor() {}
	virtual ~AbstractVisitor() {}
  public:
	virtual AbstractVisitor operator()(const tree<AstNode>&, const MapClasses* classes = 0, const MapVariables* vars = 0,
	                                   const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0) = 0;
};


#endif
