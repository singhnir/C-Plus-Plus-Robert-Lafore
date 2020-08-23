// salefunc.cpp
// passes array as argument
#include <iostream>
#include <iomanip>          //for setprecision, etc.
using namespace std;
const int DISTRICTS = 4;    //array dimensions
const int MONTHS = 3;
void display( double[DISTRICTS][MONTHS] );  //declaration
//--------------------------------------------------------------
int main()
   {                        //initialize two-dimensional array
   double sales[DISTRICTS][MONTHS]
		  = {  {  1432.07,   234.50,   654.01 },
		       {   322.00, 13838.32, 17589.88 },
		       {  9328.34,   934.00,  4492.30 },
		       { 12838.29,  2332.63,    32.93 }  };

   display(sales);          //call function; array as argument
   cout << endl;
   return 0;
   }  //end main
//--------------------------------------------------------------
//display()
//function to display 2-d array passed as argument
void display( double funsales[DISTRICTS][MONTHS] )
   {
   int d, m;

   cout << "\n\n";
   cout << "                        Month\n";
   cout << "                1         2         3";

   for(d=0; d<DISTRICTS; d++)
      {
      cout <<"\nDistrict " << d+1;
      for(m=0; m<MONTHS; m++)
         cout << setiosflags(ios::fixed) << setw(10)
              << setiosflags(ios::showpoint) << setprecision(2)
              << funsales[d][m];   //array element
      }  //end for(d)
   }  //end display