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

#ifndef __RANGE_H
#define __RANGE_H

#include "AbstractVisitor.h"
#include <cmath>

template<typename T>
void swap(T& a, T &b) {
	T c(b);
	b=a;
	a=c;
}


template<typename T>
struct Bound
{
	T lower;
	T upper;
	Bound() {}
	Bound(const Bound& _r) : lower(_r.lower),upper(_r.upper) {
		if (lower > upper)
			swap<T>(lower,upper);
	}
	Bound& operator=(const Bound& _r) {
		lower = _r.lower;
		upper = _r.upper;
		if (lower > upper)
			swap<T>(lower,upper);
		return *this;
	}
};

template<typename T>
bool operator==(const Bound<T>& b1, const Bound<T>& b2) {
	return b1.lower == b2.lower && b1.upper == b2.upper;
}

template<typename T>
static bool is_in(const Bound<T>& b1, const Bound<T>& b2) {
	if (b1.lower >=b1.lower && b1.upper <= b2.upper)
		return true;
	return false;
}

static Bound<int> Empty;

template<typename T>
static bool overlap(const Bound<T>& min, const Bound<T>& max) {
	if (min.upper >= max.lower)
		return true;
	return false;
}

template<typename T>
struct Range
{
	Bound<T> min;
	Bound<T> max;

	Range() {}
	Range(const Range& _r) : min(_r.min),max(_r.max) {}
	Range& operator=(const Bound<T>& _r) {
		min = _r.min;
		max = _r.max;
		return *this;
	}
};

class RangeChecker : public AbstractVisitor
{
  public:
	RangeChecker() {}
	virtual ~RangeChecker() {}
	virtual RangeChecker operator()(const tree<AstNode>&, const MapClasses* classes = 0, const MapVariables* vars = 0,
	                                const MapFunctions *func = 0, const MapAssignments *assigns = 0, const MapVarEquivalent *equiv = 0);
};

#endif
