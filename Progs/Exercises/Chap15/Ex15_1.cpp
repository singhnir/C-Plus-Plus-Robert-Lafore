// ex15_1.cpp
// type float stored in array, sorted by sort()
#include <iostream>
#include <algorithm>
using namespace std;

int main()
   {
   int j=0, k;
   char ch;
   float fpn, farr[100];

   do {
      cout << "Enter a floating point number: ";
      cin >> fpn;
      farr[j++] = fpn;
      cout << "Enter another ('y' or 'n'): ";
      cin >> ch;
      } while(ch == 'y');
   sort(farr, farr+j);
   for(k=0; k<j; k++)
      cout << farr[k] << ", ";
   cout << endl;
   return  0;
   }