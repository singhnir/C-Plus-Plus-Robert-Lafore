// ex12_3.cpp
// displays size of file
#include <fstream>                //for file functions
#include <iostream>
using namespace std;
#include <process.h>              //for exit()

int main(int argc, char* argv[] )
   {
   if( argc != 2 )
      { cerr << "\nFormat: filename\n"; exit(-1); }
   ifstream infile;               //create file for input
   infile.open( argv[1] );        //open file
   if( !infile )                  //check for errors
      { cerr << "\nCan't open " << argv[1]; exit(-1); }
   infile.seekg(0, ios::end);     //go to end of file
                                  // report byte number
   cout << "Size of " << argv[1] << " is " << infile.tellg();
   cout << endl;
   return 0;
   }