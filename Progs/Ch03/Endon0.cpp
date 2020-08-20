// endon0.cpp
// demonstrates WHILE loop
#include <iostream>
using namespace std;

int main()
   {
   int n = 99;       // make sure n isn't initialized to 0

   while( n != 0 )   // loop until n is 0
      cin >> n;      // read a number into n
   cout << endl;
   return 0;
   }