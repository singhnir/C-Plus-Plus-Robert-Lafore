// englcon.cpp
// constructors, adds objects using member function
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Distance                     //English Distance class
   {
   private:
      int feet;
      float inches;
   public:                         //constructor (no args)
      Distance() : feet(0), inches(0.0)                   
         {  }
                                   //constructor (two args)
      Distance(int ft, float in)  : feet(ft), inches(in)
         {  }

      void getdist()               //get length from user
         {
         cout << "\nEnter feet: ";  cin >> feet;
         cout << "Enter inches: ";  cin >> inches;
         }

      void showdist()              //display distance
         { cout << feet << "\'-" << inches << '\"'; }

      void add_dist(Distance,  Distance) const;    //declaration
   };
//--------------------------------------------------------------
                                   //add lengths d2 and d3
void Distance::add_dist(Distance d2,  Distance d3) const
   {
   inches = d2.inches + d3.inches; //add the inches
   feet = 0;                       //(for possible carry)
   if(inches >= 12.0)              //if total exceeds 12.0,
      {                            //then decrease inches
      inches -= 12.0;              //by 12.0 and
      feet++;                      //increase feet
      }                            //by 1
   feet += d2.feet + d3.feet;      //add the feet
   }
////////////////////////////////////////////////////////////////
int main()
    {
   Distance dist1, dist3;          //define two lengths
   Distance dist2(11, 6.25);       //define and initialize dist2

   dist1.getdist();                //get dist1 from user
   dist3.add_dist(dist1, dist2);   //dist3 = dist1 + dist2

                                   //display all lengths
   cout << "\ndist1 = ";  dist1.showdist();
   cout << "\ndist2 = ";  dist2.showdist();
   cout << "\ndist3 = ";  dist3.showdist();
   cout << endl;
   return 0;
   }
