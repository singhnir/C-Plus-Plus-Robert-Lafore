// ex5_2.cpp
// function raises number to a power
#include <iostream>
using namespace std;
double power( double n, int p=2);   //p has default value 2

int main()
   {
   double number, answer;
   int pow;
   char yeserno;

   cout << "\nEnter number: ";      //get number
   cin >> number;
   cout << "Want to enter a power (y/n)? ";
   cin >> yeserno;
   if( yeserno == 'y' )             //user wants a non-2 power?
      {
      cout << "Enter power: ";
      cin >> pow;
      answer = power(number, pow);  //raise number to pow
      }
   else
      answer = power(number);       //square the number
   cout << "Answer is " << answer << endl;
   return 0;
   }
//--------------------------------------------------------------
// power()
// returns number n raised to a power p
double power( double n, int p )
   {
   double result = 1.0;             //start with 1
   for(int j=0; j<p; j++)           //multiply by n
      result *= n;                  //p times
   return result;
   }