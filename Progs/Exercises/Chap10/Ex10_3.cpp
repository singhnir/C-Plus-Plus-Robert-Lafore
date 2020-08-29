// ex10_3.cpp
// sort an array of pointers to strings
#include <iostream>
#include <cstring>              //for strcmp(), etc.
using namespace std;
const int DAYS = 7;             //number of pointers in array

int main()
   {
   void bsort(char**, int);     //prototype
				//array of pointers to char
   char* arrptrs[DAYS] = { "Sunday", "Monday", "Tuesday",
			   "Wednesday", "Thursday",
			   "Friday", "Saturday"  };

   cout << "\nUnsorted:\n";
   for(int j=0; j<DAYS; j++)    //display unsorted strings
      cout << *(arrptrs+j) << endl;

   bsort(arrptrs, DAYS);        //sort the strings

   cout << "\nSorted:\n";
   for(j=0; j<DAYS; j++)        //display sorted strings
      cout << *(arrptrs+j) << endl;
   return 0;
   }
//--------------------------------------------------------------
void bsort(char** pp, int n)    //sort pointers to strings
   {
   void order(char**, char**);  //prototype
   int j, k;                    //indexes to array

   for(j=0; j<n-1; j++)         //outer loop
      for(k=j+1; k<n; k++)      //inner loop starts at outer
   order(pp+j, pp+k);           //order the pointer contents
   }
//--------------------------------------------------------------
void order(char** pp1, char** pp2)  //orders two pointers
   {                            //if string in 1st is
   if( strcmp(*pp1, *pp2) > 0)  //larger than in 2nd,
      {
      char* tempptr = *pp1;     //swap the pointers
      *pp1 = *pp2;
      *pp2 = tempptr;
      }
   }
