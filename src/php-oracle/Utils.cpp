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


#include "Utils.h"
using namespace std;

namespace utils {

void replace(string& where, const string& what, const string& by)
{
	for (string::size_type 	i  = where.find(what);
							i != string::npos;
							i  = where.find(what, i + by.size()))
		where.replace(i, what.size(), by);
}

bool start_with(const string& str, const string& what) {
	if (what.length() <= str.length())
	{
		string::const_iterator str_iter = str.begin();
		for (string::const_iterator i=what.begin(); i!=what.end();++i) {
			if (*i != *str_iter)
				return false;
			++str_iter;
		}
		return true;		
	}
	return false;
}

bool end_with(const string& str, const string& what) {
	if (what.length() <= str.length())
	{
		string::const_iterator str_iter = str.begin();
		for (string::const_reverse_iterator i=what.rbegin(); i!=what.rend();++i) {
			if (*i != *str_iter)
				return false;
			++str_iter;
		}
		return true;		
	}
	return false;
}

}

