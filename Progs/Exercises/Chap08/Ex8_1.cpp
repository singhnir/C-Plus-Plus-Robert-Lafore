// ex8_1.cpp
// overloaded '-' operator subtracts two Distances
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
         {  }                     //constructor (two args)
      Distance(int ft, float in) : feet(ft), inches(in)
         {  }
      void getdist()              //get length from user
         {
         cout << "\nEnter feet: ";  cin >> feet;
         cout << "Enter inches: ";  cin >> inches;
         }
      void showdist()             //display distance
         { cout << feet << "\'-" << inches << '\"'; }

      Distance operator + ( Distance );  //add two distances
      Distance operator - ( Distance );  //subtract two distances
   };
//--------------------------------------------------------------
                                  //add d2 to this distance
Distance Distance::operator + (Distance d2)   //return the sum
   {
   int f = feet + d2.feet;        //add the feet
   float i = inches + d2.inches;  //add the inches
   if(i >= 12.0)                  //if total exceeds 12.0,
      {                           //then decrease inches
      i -= 12.0;                  //by 12.0 and
      f++;                        //increase feet by 1
      }                           //return a temporary Distance
   return Distance(f,i);          //initialized to sum
   }
//--------------------------------------------------------------
                                  //subtract d2 from this dist
Distance Distance::operator - (Distance d2)  //return the diff
   {
   int f = feet - d2.feet;        //subtract the feet
   float i = inches - d2.inches;  //subtract the inches
   if(i < 0)                      //if inches less than 0,
      {                           //then increase inches
      i += 12.0;                  //by 12.0 and
      f--;                        //decrease feet by 1
      }                           //return a temporary Distance
   return Distance(f,i);          //initialized to difference
   }
////////////////////////////////////////////////////////////////
int main()
   {
   Distance dist1, dist3;         //define distances
   dist1.getdist();               //get dist1 from user

   Distance dist2(3, 6.25);       //define, initialize dist2

   dist3 = dist1 - dist2;         //subtract

                                  //display all lengths
   cout << "\ndist1 = ";  dist1.showdist();
   cout << "\ndist2 = ";  dist2.showdist();
   cout << "\ndist3 = ";  dist3.showdist();
   cout << endl;
   return 0;
   }
