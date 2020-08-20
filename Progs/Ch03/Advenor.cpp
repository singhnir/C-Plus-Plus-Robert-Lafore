// advenor.cpp
// demonstrates OR logical operator
#include <iostream>
using namespace std;
#include <process.h>             //for exit()
#include <conio.h>               //for getche()

int main()
   {
   char dir='a';
   int x=10, y=10;

   while( dir != '\r' )          //quit on Enter key
      {
      cout << "\n\nYour location is " << x << ", " << y;

      if( x<5 || x>15 )          //if x west of 5 OR east of 15
         cout << "\nBeware: dragons lurk here";

      cout << "\nEnter direction (n, s, e, w): ";
      dir = getche();            //get direction
      switch(dir)
         {
         case 'n': y--; break;   //update coordinates
         case 's': y++; break;
         case 'e': x++; break;
         case 'w': x--; break;
         }  //end switch
      }  //end while
   return 0;
   }  //end main()