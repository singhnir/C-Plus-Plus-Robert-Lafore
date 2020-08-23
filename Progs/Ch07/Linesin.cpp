// linesin.cpp
// reads multiple lines, terminates on '$' character
#include <iostream>
using namespace std;

const int MAX = 2000;                //max characters in string
char str[MAX];                       //string variable str

int main()
   {
   cout << "\nEnter a string:\n";
   cin.get(str, MAX, '$');           //terminate with $
   cout << "You entered:\n" << str << endl;
   return 0;
   }