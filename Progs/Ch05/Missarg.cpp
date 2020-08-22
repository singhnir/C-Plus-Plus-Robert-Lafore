// missarg.cpp
// demonstrates missing and default arguments
#include <iostream>
using namespace std;

void repchar(char='*', int=45);   //declaration with
                                  //default arguments
int main()
   {
   repchar();                     //prints 45 asterisks
   repchar('=');                  //prints 45 equal signs
   repchar('+', 30);              //prints 30 plus signs
   return 0;
   }
//--------------------------------------------------------------
// repchar()
// displays line of characters
void repchar(char ch, int n)      //defaults supplied
   {                              //   if necessary
   for(int j=0; j<n; j++)         //loops n times
      cout << ch;                 //prints ch
   cout << endl;
   }




