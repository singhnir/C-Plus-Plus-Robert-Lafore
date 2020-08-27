// ex3_2.cpp
// converts fahrenheit to centigrad, or
// centigrad to fahrenheit
#include <iostream>
using namespace std;

int main()
   {
   int response;
   double temper;

   cout << "\nType 1 to convert fahrenheit to celsius,"
	<< "\n     2 to convert celsius to fahrenheit: ";
   cin >> response;
   if( response == 1 )
      {
      cout << "Enter temperature in fahrenheit: ";
      cin >> temper;
      cout << "In celsius that's " << 5.0/9.0*(temper-32.0);
      }
   else
      {
      cout << "Enter temperature in celsius: ";
      cin >> temper;
      cout << "In fahrenheit that's " << 9.0/5.0*temper + 32.0;
      }
   cout << endl;
   return 0;
   }