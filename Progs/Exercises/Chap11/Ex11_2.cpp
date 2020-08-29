// ex11_2.cpp
// friend square() function for Distance
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Distance                    //English Distance class
   {
   private:
      int feet;
      float inches;
   public:
      Distance()                  //constructor (no args)
         { feet = 0; inches = 0.0; }
      Distance(float fltfeet)     //constructor (one arg)
         {                        //feet is integer part
         feet = static_cast<int>(fltfeet);
         inches = 12*(fltfeet-feet);  //inches is what's left
         }                        //constructor (two args)
      Distance(int ft, float in) : feet(ft), inches(in)
         {  }
      void showdist()             //display distance
         { cout << feet << "\'-" << inches << '\"'; }
      friend Distance operator * (Distance, Distance); //friend
   };
//--------------------------------------------------------------
                                  //multiply d1 by d2
Distance operator * (Distance d1, Distance d2)
   {                              
   float fltfeet1 = d1.feet + d1.inches/12;  //convert to float
   float fltfeet2 = d2.feet + d2.inches/12;
   float multfeet = fltfeet1 * fltfeet2;     //find the product
   return Distance(multfeet);     //return temp Distance
   }
////////////////////////////////////////////////////////////////
int main()
   {
   Distance dist1(3, 6.0);        //make some distances
   Distance dist2(2, 3.0);
   Distance dist3;

   dist3 = dist1 * dist2;         //multiplication

   dist3 = 10.0 * dist3;          //mult and conversion
                                  //display all distances
   cout << "\ndist1 = "; dist1.showdist();
   cout << "\ndist2 = "; dist2.showdist();
   cout << "\ndist3 = "; dist3.showdist();
   cout << endl;
   return 0;
   }
