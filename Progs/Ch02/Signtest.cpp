// signtest.cpp
// tests signed and unsigned integers
#include <iostream>
using namespace std;

int main()
   {
   int signedVar = 1500000000;           //signed   
   unsigned int unsignVar = 1500000000;  //unsigned

   signedVar = (signedVar * 2) / 3;  //calculation exceeds range
   unsignVar = (unsignVar * 2) / 3;  //calculation within range

   cout << "signedVar = " << signedVar << endl;  //wrong
   cout << "unsignVar = " << unsignVar << endl;  //OK
   return 0;
   }