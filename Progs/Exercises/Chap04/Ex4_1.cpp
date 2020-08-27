// ex4_1.cpp
// uses structure to store phone number
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
struct phone
   {
   int area;         //area code (3 digits)
   int exchange;     //exchange (3 digits)
   int number;       //number (4 digits)
   };
////////////////////////////////////////////////////////////////
int main()
   {
   phone ph1 = { 212, 767, 8900 };  //initialize phone number
   phone ph2;                       //define phone number
                                    // get phone no from user
   cout << "\nEnter your area code, exchange, and number";
   cout << "\n(Don't use leading zeros): ";
   cin >> ph2.area >> ph2.exchange >> ph2.number;

   cout << "\nMy number is "        //display numbers
	<< '(' << ph1.area << ") "
	<< ph1.exchange << '-' << ph1.number;

   cout << "\nYour number is "
	<< '(' << ph2.area << ") "
	<< ph2.exchange << '-' << ph2.number << endl;
   return 0;
   }