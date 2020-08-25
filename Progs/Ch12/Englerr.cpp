// englerr.cpp
// input checking with English Distance class
#include <iostream>
#include <string>
#include <cstdlib>                //for atoi(), atof()
using namespace std;
int isFeet(string);               //declaration
////////////////////////////////////////////////////////////////
class Distance                    //English Distance class
   {
   private:
      int feet;
      float inches;
   public:
      Distance()                  //constructor (no args)
         { feet = 0; inches = 0.0; }
      Distance(int ft, float in)  //constructor (two args)
         { feet = ft; inches = in; }
      void showdist()             //display distance
         { cout << feet << "\'-" << inches << '\"'; }
      void getdist();             //get length from user
   };
//--------------------------------------------------------------
void Distance::getdist()          //get length from user
   {
   string instr;                  //for input string

   while(true)                    //cycle until feet are right
      {
      cout << "\n\nEnter feet: ";
      cin.unsetf(ios::skipws);    //do not skip white space
      cin >> instr;               //get feet as a string
      if( isFeet(instr) )         //is it a correct feet value?
         {                        //yes
         cin.ignore(10, '\n');    //eat chars, including newline
         feet = atoi( instr.c_str() );  //convert to integer
         break;                   //break out of 'while'
         }                        //no, not an integer
      cin.ignore(10, '\n');       //eat chars, including newline
      cout << "Feet must be an integer less than 1000\n";
      }  //end while feet

   while(true)                    //cycle until inches are right
      {
      cout << "Enter inches: ";
      cin.unsetf(ios::skipws);    //do not skip white space
      cin >> inches;              //get inches (type float)
      if(inches>=12.0 || inches<0.0)
         {
         cout << "Inches must be between 0.0 and 11.99\n";
         cin.clear(ios::failbit); //"artificially" set fail bit
         }
      if( cin.good() )            //check for cin failure
         {                        //(most commonly a non-digit)
         cin.ignore(10, '\n');    //eat the newline
         break;                   //input is OK, exit 'while'
         }
      cin.clear();                //error; clear the error state
      cin.ignore(10, '\n');       //eat chars, including newline
      cout << "Incorrect inches input\n";  //start again
      }  //end while inches
   }
//--------------------------------------------------------------
int isFeet(string str)            //return true if the string
   {                              //   is a correct feet value
   int slen = str.size();         //get length
   if(slen==0 || slen > 5)        //if no input, or too long
      return 0;                   //not an int
   for(int j=0; j<slen; j++)      //check each character
                                  //if not digit or minus
      if( (str[j] < '0' || str[j] > '9') && str[j] != '-' )
         return 0;                //string is not correct feet
   double n = atof( str.c_str() );  //convert to double
   if( n<-999.0 || n>999.0 )      //is it out of range?
      return 0;                   //if so, not correct feet
   return 1;                      //it is correct feet
   }
////////////////////////////////////////////////////////////////
int main()
   {
   Distance d;                    //make a Distance object
   char ans;
   do
      {
      d.getdist();                //get its value from user
      cout << "\nDistance = ";
      d.showdist();               //display it
      cout << "\nDo another (y/n)? ";
      cin >> ans;
      cin.ignore(10, '\n');       //eat chars, including newline
      } while(ans != 'n');        //cycle until 'n'
   return 0;
   }
