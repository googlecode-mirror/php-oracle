/***********************************************************
PhpObject C++ representation for static analysis (not finished yet
though). By Romain Gaucher -- http://rgaucher.info
                   ----------------
Inspired from Forrest J. Cavalier III d-b-a Mib Software
***********************************************************/
#ifndef __LIBPHP_H
#define __LIBPHP_H

#include <string>
using namespace std;

#define function
#define var
#define extends :public
#define array  PhpObject

class PhpObject {
	PhpObject *data;
  public:
	PhpObject() {}
	PhpObject(int) {}
	PhpObject(float) {}
	PhpObject(double) {}
	PhpObject(const string&) {}
	PhpObject(const PhpObject&) {}
	PhpObject& operator=(const PhpObject&) {}
	PhpObject& operator[](unsigned) {return PhpObject();}
	PhpObject  operator[](unsigned) const {return PhpObject();}

	~PhpObject(){}
};

PhpObject


bool operator==(const PhpOject&, const PhpObject&) { return true; }
bool operator!=(const PhpOject&, const PhpObject&) { return true; }
bool operator>(const PhpOject&, const PhpObject&) { return true; }
bool operator<(const PhpOject&, const PhpObject&) { return true; }
bool operator>=(const PhpOject&, const PhpObject&) { return true; }
bool operator<=(const PhpOject&, const PhpObject&) { return true; }

PhpObject operator+(const PhpOject&, const PhpObject&) { return PhpObject(); }
PhpObject operator-(const PhpOject&, const PhpObject&) { return PhpObject(); }
PhpObject operator/(const PhpOject&, const PhpObject&) { return PhpObject(); }
PhpObject operator*(const PhpOject&, const PhpObject&) { return PhpObject(); }
PhpObject operator^(const PhpOject&, const PhpObject&) { return PhpObject(); }

#define FALSE false
#define TRUE  true
#define _APPEND_ (char *)1

#include "phpdef.h"

#endif
