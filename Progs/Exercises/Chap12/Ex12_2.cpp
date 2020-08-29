// ex12_2.cpp
// imitates COPY command
#include <fstream>                //for file functions
#include <iostream>           
using namespace std;
#include <process.h>              //for exit()

int main(int argc, char* argv[] )
   {
   if( argc != 3 )
      { cerr << "\nFormat: ocopy srcfile destfile"; exit(-1); }
   char ch;                       //character to read

   ifstream infile;               //create file for input
   infile.open( argv[1] );        //open file
   if( !infile )                  //check for errors
      { cerr << "\nCan't open " << argv[1]; exit(-1); }

   ofstream outfile;              //create file for output
   outfile.open( argv[2] );       //open file
   if( !outfile )                 //check for errors
      { cerr << "\nCan't open " << argv[2]; exit(-1); }

   while( infile )                //until EOF
      {
      infile.get(ch);             //read a character
      outfile.put(ch);            //write the character
      }
   return 0;
   }