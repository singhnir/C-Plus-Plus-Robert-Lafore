// comline.cpp
// demonstrates command-line arguments
#include <iostream>
using namespace std;

int main(int argc, char* argv[] )
   {
   cout << "\nargc = " << argc << endl;  //number of arguments

   for(int j=0; j<argc; j++)             //display arguments
      cout << "Argument " << j << " = " << argv[j] << endl;
   return 0;
   }