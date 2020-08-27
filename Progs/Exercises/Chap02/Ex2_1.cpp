// ex2_1.cpp
// converts gallons to cubic feet
#include <iostream>
using namespace std;

int main()
   {
   float gallons, cufeet;

   cout << "\nEnter quantity in gallons: ";
   cin >> gallons;
   cufeet = gallons / 7.481;
   cout << "Equivalent in cublic feet is " << cufeet << endl;
   return 0;
   }