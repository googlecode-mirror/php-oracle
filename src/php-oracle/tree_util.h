/*
   A collection of miscellaneous utilities that operate on the templated 
   tree.hh class.

   (At the moment only a printing utility.
   Linda Buisman, linda.buisman@studentmail.newcastle.edu.au)

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#ifndef tree_util_hh_
#define tree_util_hh_

#include <iostream>
#include <string>
#include "tree.h"

namespace kptree {

// Iterate over all roots (the head) and print each one on a new line
// by calling printSingleRoot.

template<class T>
void print_tree_bracketed(const tree<T>& t, std::ostream& str)
   {
   int headCount = t.number_of_siblings(t.begin());
   int headNum = 0;
   for(typename tree<T>::sibling_iterator iRoots = t.begin(); iRoots != t.end(); iRoots++) {
      print_subtree_bracketed(t,iRoots,str,"");
      if (headNum <= headCount - 1) {
         str << std::endl;
         }
      }
   }


// Print everything under this root in a flat, bracketed structure.
template<class T>
void print_subtree_bracketed(const tree<T>& t, typename tree<T>::iterator iRoot, std::ostream& str, std::string padding = "") 
   {
   if(t.empty()) return;
   if (t.number_of_children(iRoot) == 0) {
      str << padding << *iRoot << std::endl;
      }
   else {
      // parent
      str << padding << *iRoot << std::endl;
      // child1, ..., childn
      int siblingNum;
      typename tree<T>::sibling_iterator iChildren;
      for (iChildren = t.begin(iRoot), siblingNum = 0; iChildren != t.end(iRoot); ++iChildren) {
         // recursively print child
         print_subtree_bracketed(t,iChildren,str, padding + " ");
         // comma after every child except the last one
         }
      }
   }
}

#endif
