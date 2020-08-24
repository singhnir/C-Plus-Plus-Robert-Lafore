// ptrinc.cpp
// array accessed with pointer
#include <iostream>
using namespace std;

int main()
   {
   int intarray[] = { 31, 54, 77, 52, 93 }; //array
   int* ptrint;                             //pointer to int
   ptrint = intarray;                       //points to intarray

   for(int j=0; j<5; j++)                   //for each element,
      cout << *(ptrint++) << endl;          //print value
   return 0;
   }