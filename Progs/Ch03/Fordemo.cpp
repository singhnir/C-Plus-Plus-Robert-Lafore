// fordemo.cpp
// demonstrates simple FOR loop
#include <iostream>
using namespace std;

int main()
   {
   int j;                     //define a loop variable

   for(j=0; j<15; j++)        //loop from 0 to 14,
      cout << j * j << "  ";  //displaying the square of j
   cout << endl;
   return 0;
   }