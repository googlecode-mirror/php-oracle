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

#ifndef __UTILS_H
#define __UTILS_H

#include <string>
#include <sstream>

template <class T>
bool from_string(T& t, const std::string& s) {
	std::istringstream iss(s, std::istringstream::in);
	return !(iss >> t).fail();	
}

template <class T>
std::string to_string(const T& t) {
	std::ostringstream oss;
	oss << t;
	return oss.str();
}


namespace utils {

void replace(std::string& where, const std::string& what, const std::string& by);

bool start_with(const std::string& str, const std::string& what);
bool   end_with(const std::string& str, const std::string& what);

}


#endif
