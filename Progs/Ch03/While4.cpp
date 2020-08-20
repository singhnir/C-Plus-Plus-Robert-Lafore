// while4.cpp
// prints numbers raised to fourth power
#include <iostream>
#include <iomanip>               //for setw
using namespace std;

int main()
   {
   int pow=1;                    //power initially 1
   int numb=1;                   //numb goes from 1 to ???

   while( pow<10000 )            //loop while power <= 4 digits
      {
      cout << setw(2) << numb;         //display number
      cout << setw(5) << pow << endl;  //display fourth power
      ++numb;                          //get ready for next power
      pow = numb*numb*numb*numb;       //calculate fourth power
      }
   cout << endl;
   return 0;
   }