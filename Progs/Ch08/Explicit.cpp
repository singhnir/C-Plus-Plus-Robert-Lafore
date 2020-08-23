//explicit.cpp
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Distance                  //English Distance class
   {
   private:
      const float MTF;          //meters to feet 
      int feet;
      float inches;
   public:                      //no-args constructor 
      Distance() : feet(0), inches(0.0), MTF(3.280833F)      
         {  }
                                //EXPLICIT one-arg constructor
      explicit Distance(float meters) : MTF(3.280833F)
         {                        
         float fltfeet = MTF * meters;
         feet = int(fltfeet);         
         inches = 12*(fltfeet-feet);   
         }                        
      void showdist()           //display distance
         { cout << feet << "\'-" << inches << '\"'; }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   void fancyDist(Distance);    //declaration
   Distance dist1(2.35F);       //uses 1-arg constructor to
                                //convert meters to Distance

// Distance dist1 = 2.35F;      //ERROR if ctor is explicit
   cout << "\ndist1 = "; dist1.showdist(); 

   float mtrs = 3.0F;
   cout << "\ndist1 ";
// fancyDist(mtrs);             //ERROR if ctor is explicit

   return 0;
   }
//--------------------------------------------------------------
void fancyDist(Distance d)
   {
   cout << "(in feet and inches) = ";
   d.showdist();
   cout << endl;
   }
