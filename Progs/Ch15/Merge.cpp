// merge.cpp
// merges two containers into a third
#include <iostream>
#include <algorithm>          //for merge()
using namespace std;

int src1[] = { 2, 3, 4, 6, 8 };
int src2[] = { 1, 3, 5 };
int dest[8];

int main()
   {                          //merge src1 and src2 into dest
   merge(src1, src1+5, src2, src2+3, dest);
   for(int j=0; j<8; j++)     // display dest
      cout << dest[j] << ' ';
   cout << endl;
   return 0;
   }
