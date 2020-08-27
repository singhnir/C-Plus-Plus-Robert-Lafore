// ex2_3.cpp
// exercises arithmetic assignment and decrement
#include <iostream>
using namespace std;

int main()
   {
   int var = 10;

   cout << var << endl;      // var is 10
   var *= 2;                 // var becomes 20
   cout << var-- << endl;    // displays var, then decrements it
   cout << var << endl;      // var is 19
   return 0;
   }