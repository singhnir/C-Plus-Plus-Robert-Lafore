// listout.cpp
// iterator and for loop for output
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
   {
   int arr[] = { 2, 4, 6, 8 };
   list<int> theList;

   for(int k=0; k<4; k++)      //fill list with array elements
      theList.push_back( arr[k] );

   list<int>::iterator iter;   //iterator to list-of-ints

   for(iter = theList.begin(); iter != theList.end(); iter++)
      cout << *iter << ' ';    //display the list
   cout << endl;
   return 0;
   }
