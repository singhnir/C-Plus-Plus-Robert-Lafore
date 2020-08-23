// safetyin.cpp
// avoids buffer overflow with cin.width
#include <iostream>
#include <iomanip>                  //for setw
using namespace std;

int main()
   {
   const int MAX = 20;              //max characters in string
   char str[MAX];                   //string variable str

   cout << "\nEnter a string: ";
   cin >> setw(MAX) >> str;         //put string in str,
                                    // no more than MAX chars
   cout << "You entered: " << str << endl;  
   return 0;
   }