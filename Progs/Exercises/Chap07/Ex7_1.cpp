// ex7_1.cpp
// reverses a C-string
#include <iostream>
#include <cstring>                  //for strlen()
using namespace std;

int main()
   {
   void reversit( char[] );         //prototype
   const int MAX = 80;              //array size
   char str[MAX];                   //string

   cout << "\nEnter a string: ";    //get string from user
   cin.get(str, MAX);

   reversit(str);                   //reverse the string

   cout << "Reversed string is: ";  //display it
   cout << str << endl;
   return 0;
   }
//--------------------------------------------------------------
//reversit()
//function to reverse a string passed to it as an argument
void reversit( char s[] )
   {
   int len = strlen(s);             //find length of string
   for(int j = 0; j < len/2; j++)   //swap each character
      {                             //   in first half
      char temp = s[j];             //   with character
      s[j] = s[len-j-1];            //   in second half
      s[len-j-1] = temp;
      }
   }
