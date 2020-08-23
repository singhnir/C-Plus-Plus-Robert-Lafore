// salemon.cpp
// displays sales chart using 2-d array
#include <iostream>
#include <iomanip>                  //for setprecision, etc.
using namespace std;

const int DISTRICTS = 4;            //array dimensions
const int MONTHS = 3;

int main()
   {
   int d, m;
   double sales[DISTRICTS][MONTHS];  //two-dimensional array
                                     //definition
   cout << endl;
   for(d=0; d<DISTRICTS; d++)        //get array values
      for(m=0; m<MONTHS; m++)
         {
         cout << "Enter sales for district " << d+1;
         cout << ", month " << m+1 << ": ";
         cin >> sales[d][m];         //put number in array
         }

   cout << "\n\n";                   
   cout << "                        Month\n";
   cout << "                1         2         3";
   for(d=0; d<DISTRICTS; d++)
      {
      cout <<"\nDistrict " << d+1;
      for(m=0; m<MONTHS; m++)        //display array values
         cout << setiosflags(ios::fixed)      //not exponential
              << setiosflags(ios::showpoint)  //always use point
              << setprecision(2)              //digits to right
              << setw(10)                     //field width
              << sales[d][m];        //get number from array
      }  //end for(d)
   cout << endl;
   return 0;
   }  //end main