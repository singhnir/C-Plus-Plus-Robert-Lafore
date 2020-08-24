// ptracc.cpp
// accessing the variable pointed to
#include <iostream>
using namespace std;

int main()
   {
   int var1 = 11;             //two integer variables
   int var2 = 22;

   int* ptr;                  //pointer to integers

   ptr = &var1;               //pointer points to var1
   cout << *ptr << endl;      //print contents of pointer (11)

   ptr = &var2;               //pointer points to var2
   cout << *ptr << endl;      //print contents of pointer (22)
   return 0;
   }