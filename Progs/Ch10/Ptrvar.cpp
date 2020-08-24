// ptrvar.cpp
// pointers (address variables)
#include <iostream>
using namespace std;

int main()
   {
   int var1 = 11;             //two integer variables
   int var2 = 22;

   cout << &var1 << endl      //print addresses of variables
        << &var2 << endl << endl;

   int* ptr;                  //pointer to integers

   ptr = &var1;               //pointer points to var1
   cout << ptr << endl;       //print pointer value

   ptr = &var2;               //pointer points to var2
   cout << ptr << endl;       //print pointer value
   return 0;
   }