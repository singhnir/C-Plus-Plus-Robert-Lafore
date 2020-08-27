// ex3_1.cpp
// displays multiples of a number
#include <iostream>
#include <iomanip>                     //for setw()
using namespace std;

int main()
   {
   unsigned long n;                    //number

   cout << "\nEnter a number: ";
   cin >> n;                           //get number
   for(int j=1; j<=200; j++)           //loop from 1 to 200
      {
      cout << setw(5) << j*n << "  ";  //print multiple of n
      if( j%10 == 0 )                  //every 10 numbers,
         cout << endl;                 //start new line
      }
   return 0;
   }