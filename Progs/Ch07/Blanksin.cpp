// blanksin.cpp
// reads string with embedded blanks
#include <iostream>
using namespace std;

int main()
   {
   const int MAX = 80;              //max characters in string
   char str[MAX];                   //string variable str

   cout << "\nEnter a string: ";
   cin.get(str, MAX);               //put string in str
   cout << "You entered: " << str << endl;
   return 0;
   }