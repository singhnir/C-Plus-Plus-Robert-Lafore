// extern.cpp
// demonstrates global variables
#include <iostream>
using namespace std;
#include <conio.h>        //for getch()

char ch = 'a';            //global variable ch

void getachar();          //function declarations
void putachar();

int main()
   {
   while( ch != '\r' )    //main() accesses ch
      {
      getachar();
      putachar();
      }
   cout << endl;
   return 0;
   }
//--------------------------------------------------------------
void getachar()           //getachar() accesses ch
   {
   ch = getch();
   }
//--------------------------------------------------------------
void putachar()           //putachar() accesses ch
   {
   cout << ch;
   }