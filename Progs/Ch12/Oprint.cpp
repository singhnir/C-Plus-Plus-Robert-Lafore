// oprint.cpp
// imitates print command
#include <fstream>                //for file functions
#include <iostream>
using namespace std;
#include <process.h>              //for exit()

int main(int argc, char* argv[] )
   {
   if(argc != 2)
      {
      cerr << "\nFormat: oprint filename\n";
      exit(-1);
      }
   char ch;                       //character to read
   ifstream infile;               //create file for input
   infile.open( argv[1] );        //open file
   if( !infile )                  //check for errors
      {
      cerr << "\nCan't open " << argv[1] << endl;
      exit(-1);
      }
   ofstream outfile;              //make file
   outfile.open("PRN");           //open it for printer
   while( infile.get(ch) != 0 )   //read a character
      outfile.put(ch);            //write character to printer
   outfile.put('\x0C');           //formfeed to eject page
   return 0;
   }