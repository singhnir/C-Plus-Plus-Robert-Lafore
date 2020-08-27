// ex3_3.cpp
// makes a number out of digits
#include <iostream>
using namespace std;
#include <conio.h>                   //for getche()

int main()
   {
   char ch;                    
   unsigned long total = 0;          //this holds the number

   cout << "\nEnter a number: ";
   while( (ch=getche()) != '\r' )    //quit on Enter
      total = total*10 + ch-'0';     //add digit to total*10
   cout << "\nNumber is: " << total << endl;
   return 0;
   }