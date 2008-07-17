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

#ifndef __PROJECT_MANAGER_H
#define __PROJECT_MANAGER_H

#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include "Utils.h"


class ProjectManager {
  protected:
	std::list<std::string> files;
	std::list<std::string> extensions;
	std::list<std::string> binaries;

  protected:
	ProjectManager(const ProjectManager&) {}
	ProjectManager& operator=(const ProjectManager&) {return *this;};

  public:
	
	ProjectManager() {}
	void assessement() const;
};

#endif
