// twostr.cpp
// strings defined using array and pointer notation
#include <iostream>
using namespace std;

int main()
   {
   char str1[] = "Defined as an array";
   char* str2 = "Defined as a pointer";

   cout << str1 << endl;    // display both strings
   cout << str2 << endl;

// str1++;                  // can't do this; str1 is a constant
   str2++;                  // this is OK, str2 is a pointer

   cout << str2 << endl;    // now str2 starts "efined..."
   return 0;
   }