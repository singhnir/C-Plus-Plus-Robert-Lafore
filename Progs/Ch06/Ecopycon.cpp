// ecopycon.cpp
// initialize objects using default copy constructor
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Distance                    //English Distance class
   {
   private:
      int feet;
      float inches;
   public:                        //constructor (no args)
      Distance() : feet(0), inches(0.0)                
         {  }                     
      //Note: no one-arg constructor
                                  //constructor (two args)
      Distance(int ft, float in)  : feet(ft), inches(in) 
         {  }                     

      void getdist()              //get length from user
         {
         cout << "\nEnter feet: ";  cin >> feet;
         cout << "Enter inches: ";  cin >> inches;
         }
      void showdist()             //display distance
         { cout << feet << "\'-" << inches << '\"'; }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   Distance dist1(11, 6.25);      //two-arg constructor
   Distance dist2(dist1);         //one-arg constructor
   Distance dist3 = dist1;        //also one-arg constructor

                                  //display all lengths
   cout << "\ndist1 = ";  dist1.showdist();
   cout << "\ndist2 = ";  dist2.showdist();
   cout << "\ndist3 = ";  dist3.showdist();
   cout << endl;
   return 0;
   }
