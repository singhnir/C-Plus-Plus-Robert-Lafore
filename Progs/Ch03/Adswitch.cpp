// adswitch.cpp
// demonstrates SWITCH with adventure program
#include <iostream>
using namespace std;
#include <conio.h>                             //for getche()

int main()
   {
   char dir='a';
   int x=10, y=10;

   while( dir != '\r' )
      {
      cout << "\nYour location is " << x << ", " << y;
      cout << "\nEnter direction (n, s, e, w): ";
      dir = getche();                           //get character
      switch(dir)                               //switch on it
         {
         case 'n':  y--; break;                 //go north
         case 's':  y++; break;                 //go south
         case 'e':  x++; break;                 //go east
         case 'w':  x--; break;                 //go west
         case '\r': cout << "Exiting\n"; break; //Enter key
         default:   cout << "Try again\n";      //unknown char
         }  //end switch
      }  //end while
   return 0;
   }  //end main