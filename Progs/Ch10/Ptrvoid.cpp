// ptrvoid.cpp
// pointers to type void
#include <iostream>
using namespace std;

int main()
   {
   int intvar;                //integer variable
   float flovar;              //float variable

   int* ptrint;               //define pointer to int
   float* ptrflo;             //define pointer to float
   void* ptrvoid;             //define pointer to void

   ptrint = &intvar;          //ok, int* to int*
// ptrint = &flovar;          //error, float* to int*
// ptrflo = &intvar;          //error, int* to float*
   ptrflo = &flovar;          //ok, float* to float*

   ptrvoid = &intvar;         //ok, int* to void*
   ptrvoid = &flovar;         //ok, float* to void*
   return 0;
   }