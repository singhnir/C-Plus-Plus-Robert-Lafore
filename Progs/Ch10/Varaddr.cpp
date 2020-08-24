// varaddr.cpp
// addresses of variables
#include <iostream>
using namespace std;

int main()
   {
   int var1 = 11;           //define and initialize
   int var2 = 22;           //three variables
   int var3 = 33;

   cout << &var1 << endl    //print the addresses
        << &var2 << endl    //of these variables
        << &var3 << endl;
   return 0;
   }