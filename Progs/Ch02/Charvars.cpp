// charvars.cpp
// demonstrates character variables
#include <iostream>        //for cout, etc.
using namespace std;

int main()
   {
   char charvar1 = 'A';    //define char variable as character
   char charvar2 = '\t';   //define char variable as tab

   cout << charvar1;       //display character
   cout << charvar2;       //display character
   charvar1 = 'B';         //set char variable to char constant
   cout << charvar1;       //display character
   cout << '\n';           //display newline character
   return 0;
   }