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

#ifndef __AST_RANGE_H
#define __AST_RANGE_H

#include "tree.h"
class AstNode;

class AstRange
{
	tree<AstNode>::iterator min;
	tree<AstNode>::iterator max;
  public:
	AstRange() {}
	AstRange(const tree<AstNode>::iterator& _min, const tree<AstNode>::iterator& _max) : min(_min), max(_max) {}
	AstRange(const AstRange& a) : min(a.min), max(a.max) {}
	AstRange& operator= (const AstRange& a) {
		min = a.min;
		max = a.max;
		return *this;
	}

	inline void setMin(const tree<AstNode>::iterator& _min) { min = _min; }
	inline void setMax(const tree<AstNode>::iterator& _max) { max = _max; }
	inline tree<AstNode>::iterator& getMin() { return min; }
	inline tree<AstNode>::iterator& getMax() { return max; }

	inline bool inRange(const tree<AstNode>::iterator& a) const {
		tree<AstNode>::iterator temp = min;
		for (;temp != max; ++temp)
			if (temp == a)
				return true;
		return false;
	}
};

typedef AstRange AstNodeRange;

#endif
