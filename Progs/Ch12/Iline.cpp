// iline.cpp
// file input with strings
#include <fstream>                  //for file functions
#include <iostream>
using namespace std;

int main()
   {
   const int MAX = 80;              //size of buffer
   char buffer[MAX];                //character buffer
   ifstream infile("TEST.TXT");     //create file for input
   while( !infile.eof() )           //until end-of-file
      {
      infile.getline(buffer, MAX);  //read a line of text
      cout << buffer << endl;       //display it
      }
   return 0;
   }