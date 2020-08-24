// passptr.cpp
// arguments passed by pointer
#include <iostream>
using namespace std;

int main()
   {
   void centimize(double*);    //prototype

   double var = 10.0;          //var has value of 10 inches
   cout << "var = " << var << " inches" << endl;

   centimize(&var);            //change var to centimeters
   cout << "var = " << var << " centimeters" << endl;
   return 0;
   }
//--------------------------------------------------------------
void centimize(double* ptrd)
   {
   *ptrd *= 2.54;              //*ptrd is the same as var
   }
