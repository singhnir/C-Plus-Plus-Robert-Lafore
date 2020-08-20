// ifelse.cpp
// demonstrates IF...ELSE statememt
#include <iostream>
using namespace std;

int main()
   {
   int x;

   cout << "\nEnter a number: ";
   cin >> x;
   if( x > 100 )
      cout << "That number is greater than 100\n";
   else
      cout << "That number is not greater than 100\n";
   return 0;
   }