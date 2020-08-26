// xdist.cpp
// exceptions with Distance class
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Distance                    //English Distance class
   {
   private:
      int feet;
      float inches;
   public:
      class InchesEx { };         //exception class
//--------------------------------------------------------------
      Distance()                  //constructor (no args)
         { feet = 0; inches = 0.0; }
//--------------------------------------------------------------
      Distance(int ft, float in)  //constructor (two args)
         {
         if(in >= 12.0)           //if inches too big,
            throw InchesEx();     //throw exception
         feet = ft;
         inches = in;
         }
//--------------------------------------------------------------
      void getdist()              //get length from user
	      {
	      cout << "\nEnter feet: ";  cin >> feet;
	      cout << "Enter inches: ";  cin >> inches;
         if(inches >= 12.0)       //if inches too big,
            throw InchesEx();     //throw exception
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
      dist2.getdist();            //get distance
                                  //display distances
      cout << "\ndist1 = ";  dist1.showdist();
      cout << "\ndist2 = ";  dist2.showdist();
      }
   catch(Distance::InchesEx)      //catch exceptions
      {
      cout << "\nInitialization error: "
              "inches value is too large.";
      }
   cout << endl;
   return 0;
   }
