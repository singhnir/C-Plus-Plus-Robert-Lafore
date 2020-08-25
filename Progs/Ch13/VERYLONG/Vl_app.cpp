// vl_app.cpp
// calculates factorials of larger numbers using verylong class
#include "verylong.h"                  //verylong header file

int main()
   {
   unsigned long numb, j;
   verylong fact=1;                    //initialize verylong

   cout << "\n\nEnter number: ";
   cin >> numb;                        //input a long int

   for(j=numb; j>0; j--)               //factorial is numb *
      fact = fact * j;                 //   numb-1 * numb-2 *
   cout << "Factorial is ";            //   numb-3 and so on
   fact.putvl();                       //display factorial
   cout << endl;
   return 0;
   }