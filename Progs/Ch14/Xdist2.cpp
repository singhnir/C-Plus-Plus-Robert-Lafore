// xdist2.cpp
// exceptions with arguments
#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////
class Distance                    //English Distance class
   {
   private:
      int feet;
      float inches;
   public:
//--------------------------------------------------------------
      class InchesEx              //exception class
          {
          public:
             string origin;       //for name of routine
             float iValue;        //for faulty inches value

             InchesEx(string or, float in)  //2-arg constructor
                {
                origin = or;      //store string
                iValue = in;      //store inches
                }
          };                      //end of exception class
//--------------------------------------------------------------
      Distance()                  //constructor (no args)
         { feet = 0; inches = 0.0; }
//--------------------------------------------------------------
      Distance(int ft, float in)  //constructor (two args)
         {
         if(in >= 12.0)
            throw InchesEx("2-arg constructor", in);
         feet = ft;
         inches = in;
         }
//--------------------------------------------------------------
      void getdist()              //get length from user
	      {
	      cout << "\nEnter feet: ";  cin >> feet;
	      cout << "Enter inches: ";  cin >> inches;
         if(inches >= 12.0)
            throw InchesEx("getdist() function", inches);
	      }
//--------------------------------------------------------------
      void showdist()             //display distance
	      { cout << feet << "\'-" << inches << '\"'; }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   try
      {
      Distance dist1(17, 3.5);    //2-arg constructor
      Distance dist2;             //no-arg constructor
      dist2.getdist();            //get value
                                  //display distances
      cout << "\ndist1 = ";  dist1.showdist();
      cout << "\ndist2 = ";  dist2.showdist();
      }
   catch(Distance::InchesEx ix)   //exception handler
      {
      cout << "\nInitialization error in " << ix.origin
           << ".\n   Inches value of " << ix.iValue
           << " is too large.";
      }
   cout << endl;
   return 0;
   }
