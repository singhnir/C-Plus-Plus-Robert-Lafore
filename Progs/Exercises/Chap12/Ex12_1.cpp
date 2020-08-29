// ex12_1.cpp
// write array
#include <iostream>
#include <fstream>              // for file streams
using namespace std;
////////////////////////////////////////////////////////////////
class Distance                    // English Distance class
   {
   private:
      int feet;
      float inches;
   public:
      Distance() : feet(0), inches(0.0) // constructor (no args)
         {  }                           // constructor (two args)
      Distance(int ft, float in) : feet(ft), inches(in)  
         {  }
      void getdist()              // get length from user
         {
         cout << "\n   Enter feet: ";  cin >> feet;
         cout << "   Enter inches: ";  cin >> inches;
         }
      void showdist()             // display distance
	 { cout << feet << "\'-" << inches << '\"'; }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   char ch;
   Distance dist;                 // create a Distance object
   fstream file;                  // create input/output file
				  // open it for append
   file.open("DIST.DAT", ios::binary | ios::app | 
                         ios::out | ios::in );

   do                             // data from user to file
      {
      cout << "\nDistance";
      dist.getdist();             // get a distance
				  // write to file
      file.write( (char*)&dist, sizeof(dist) );
      cout << "Enter another distance (y/n)? ";
      cin >> ch;
      }
   while(ch=='y');                // quit on 'n'

   file.seekg(0);                 // reset to start of file
				  // read first distance
   file.read( (char*)&dist, sizeof(dist) );
   int count = 0;
   while( !file.eof() )           // quit on EOF
      {
      cout << "\nDistance " << ++count << ": "; // display dist
      dist.showdist();
      file.read( (char*)&dist, sizeof(dist) );  // read another
      }                                         // distance
   cout << endl;
   return 0;
   }
