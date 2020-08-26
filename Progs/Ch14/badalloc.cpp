// badalloc.cpp
// demonstrates bad_alloc exception
#include <iostream>
using namespace std;

int main()
   {
   const unsigned long SIZE = 10000;    //memory size
   char* ptr;                           //pointer to memory

   try
      {
      ptr = new char[SIZE];             //allocate SIZE bytes
      }
   catch(bad_alloc)                     //exception handler
      {
      cout << "\nbad_alloc exception: can't allocate memory.\n";
      return(1);
      }
   delete[] ptr;                        //deallocate memory
   cout << "\nMemory use is successful.\n";
   return 0;
   }