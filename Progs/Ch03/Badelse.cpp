// badelse.cpp
// demonstrates ELSE matched with wrong IF
#include <iostream>
using namespace std;

int main()
   {
   int a, b, c;
   cout << "Enter three numbers, a, b, and c:\n";
   cin >> a >> b >> c;

   if( a==b )
      if( b==c )
         cout << "a, b, and c are the same\n";
   else
      cout << "a and b are different\n";
   return 0;
   }