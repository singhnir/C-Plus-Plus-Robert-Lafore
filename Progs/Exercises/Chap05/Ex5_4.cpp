// ex5_4.cpp
// function returns larger of two distances
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
struct Distance                 // English distance
   {
   int feet;
   float inches;
   };
////////////////////////////////////////////////////////////////				
Distance bigengl(Distance, Distance);  //declarations
void engldisp(Distance);

int main()
   {
   Distance d1, d2, d3;         //define three lengths
                                //get length d1 from user
   cout << "\nEnter feet: ";  cin >> d1.feet;
   cout << "Enter inches: ";  cin >> d1.inches;
                                //get length d2 from user
   cout << "\nEnter feet: ";  cin >> d2.feet;
   cout << "Enter inches: ";  cin >> d2.inches;

   d3 = bigengl(d1, d2);        //d3 is larger of d1 and d2
                                //display all lengths
   cout << "\nd1="; engldisp(d1);
   cout << "\nd2="; engldisp(d2);
   cout << "\nlargest is "; engldisp(d3); cout << endl;
   return 0;
   }
//--------------------------------------------------------------
// bigengl()
// compares two structures of type Distance, returns the larger
Distance bigengl( Distance dd1, Distance dd2 )
   {
   if(dd1.feet > dd2.feet)      //if feet are different, return
      return dd1;               //the one with the largest feet
   if(dd1.feet < dd2.feet)
      return dd2;
   if(dd1.inches > dd2.inches)  //if inches are different,
      return dd1;               //return one with largest
   else                         //inches, or dd2 if equal
      return dd2;
   }
//--------------------------------------------------------------
// engldisp()
// display structure of type Distance in feet and inches
void engldisp( Distance dd )   
   {
   cout << dd.feet << "\'-" << dd.inches << "\"";
   }
