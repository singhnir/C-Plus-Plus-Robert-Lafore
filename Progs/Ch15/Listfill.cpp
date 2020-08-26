// listfill.cpp
// uses iterator to fill list with data
#include <iostream>
#include <list>
using namespace std;

int main()
   {
   list<int> iList(5);      // empty list holds 5 ints
   list<int>::iterator it;  // iterator
   int data = 0;
                            // fill list with data
   for(it = iList.begin(); it != iList.end(); it++)
      *it = data += 2;
                            // display list
   for(it = iList.begin(); it != iList.end(); it++)
      cout << *it << ' ';
   cout << endl;
   return 0;
   }
