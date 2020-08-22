// overengl.cpp
// demonstrates overloaded functions
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
struct Distance               //English distance
   {
   int feet;
   float inches;
   };
////////////////////////////////////////////////////////////////
void engldisp( Distance );     //declarations
void engldisp( float );

int main()
   {
   Distance d1;                //distance of type Distance
   float d2;                   //distance of type float
                               //get length d1 from user
   cout << "\nEnter feet: ";  cin >> d1.feet;
   cout << "Enter inches: ";  cin >> d1.inches;
                               //get length d2 from user
   cout << "Enter entire distance in inches: "; cin >> d2;

   cout << "\nd1 = ";
   engldisp(d1);               //display length 1
   cout << "\nd2 = ";          
   engldisp(d2);               //display length 2
   cout << endl;
   return 0;
   }
//--------------------------------------------------------------
// engldisp()
// display structure of type Distance in feet and inches
void engldisp( Distance dd )   //parameter dd of type Distance
   {
   cout << dd.feet << "\'-" << dd.inches << "\"";
   }
//--------------------------------------------------------------
// engldisp()
// display variable of type float in feet and inches
void engldisp( float dd )      //parameter dd of type float
   {
   int feet = static_cast<int>(dd / 12);
   float inches = dd - feet*12;
   cout << feet << "\'-" << inches << "\"";
   }
