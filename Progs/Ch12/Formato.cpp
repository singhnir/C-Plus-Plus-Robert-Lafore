// formato.cpp
// writes formatted output to a file, using <<
#include <fstream>                //for file I/O
#include <iostream>
#include <string>
using namespace std;

int main()
   {
   char ch = 'x';
   int j = 77;
   double d = 6.02;
   string str1 = "Kafka";         //strings without
   string str2 = "Proust";        //   embedded spaces

   ofstream outfile("fdata.txt"); //create ofstream object

   outfile << ch                  //insert (write) data
           << j
           << ' '                 //needs space between numbers
           << d
           << str1
           << ' '                 //needs spaces between strings
           << str2;
   cout << "File written\n";
   return 0;
   }