// condi.cpp
// prints 'x' every 8 columns
// demonstrates conditional operator
#include <iostream>
using namespace std;

int main()
   {
   for(int j=0; j<80; j++)          //for every column,
      {                             //ch is 'x' if column is
      char ch = (j%8) ? ' ' : 'x';  //multiple of 8, and
      cout << ch;                   //' ' (space) otherwise
      }
   return 0;
   }