// ex15_3.cpp
// home-made reverse() algorithm reverses a list
#include <iostream>
#include <list>
using namespace std;

int main()
   {
   int j;

   list<int> theList;
   list<int>::iterator iter1;
   list<int>::iterator iter2;

   for(j=2; j<16; j+=2)           //fill list with 2, 4, 6, ...
      theList.push_back(j);

   cout << "Before reversal: ";   //display list
   for(iter1=theList.begin(); iter1 != theList.end(); iter1++)
      cout << *iter1 << " ";

   iter1 = theList.begin();       //set to first element
   iter2 = theList.end();         //set to one-past-last
   --iter2;                       //move to last

   while(iter1 != iter2)
      {
      swap(*iter1, *iter2);       //swap front and back
      ++iter1;                    //increment front
      if(iter1==iter2)            //if even number of elements
         break;
      --iter2;                    //decrement back
      }

   cout << "\nAfter reversal: ";  //display list
   for(iter1=theList.begin(); iter1 != theList.end(); iter1++)
      cout << *iter1 << " ";
   cout << endl;
   return 0;
   }
