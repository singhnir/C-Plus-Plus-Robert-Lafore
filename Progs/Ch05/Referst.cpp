// referst.cpp
// demonstrates passing structure by reference
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
struct Distance                       //English distance
   {
   int feet;
   float inches;
   };
////////////////////////////////////////////////////////////////
void scale( Distance&, float );       //function
void engldisp( Distance );            //declarations
 
int main()
   {
   Distance d1 = { 12, 6.5 };         //initialize d1 and d2
   Distance d2 = { 10, 5.5 };

   cout << "d1 = "; engldisp(d1);     //display old d1 and d2
   cout << "\nd2 = "; engldisp(d2);

   scale(d1, 0.5);                    //scale d1 and d2
   scale(d2, 0.25);

   cout << "\nd1 = "; engldisp(d1);   //display new d1 and d2
   cout << "\nd2 = "; engldisp(d2);
   cout << endl;
   return 0;
   }
//--------------------------------------------------------------
// scale()
// scales value of type Distance by factor
void scale( Distance& dd, float factor)
   {
   float inches = (dd.feet*12 + dd.inches) * factor;
   dd.feet = static_cast<int>(inches / 12);
   dd.inches = inches - dd.feet * 12;
   }
//--------------------------------------------------------------
// engldisp()
// display structure of type Distance in feet and inches
void engldisp( Distance dd )   //parameter dd of type Distance
   {
   cout << dd.feet << "\'-" << dd.inches << "\"";
   }
