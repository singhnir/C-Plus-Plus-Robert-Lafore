// cubelist.cpp
// lists cubes from 1 to 10
#include <iostream>
#include <iomanip>                      //for setw
using namespace std;

int main()
   {
   int numb;                            //define loop variable

   for(numb=1; numb<=10; numb++)        //loop from 1 to 10
      {
      cout << setw(4) << numb;          //display 1st column
      int cube = numb*numb*numb;        //calculate cube
      cout << setw(6) << cube << endl;  //display 2nd column
      }
   return 0;
   }