// engldisp.cpp
// demonstrates passing structure as argument
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
struct Distance               //English distance
   {
   int feet;
   float inches;
   };
////////////////////////////////////////////////////////////////
void engldisp( Distance );     //declaration

int main()
   {
   Distance d1, d2;            //define two lengths

                               //get length d1 from user
   cout << "Enter feet: ";  cin >> d1.feet;
   cout << "Enter inches: ";  cin >> d1.inches;

                               //get length d2 from user
   cout << "\nEnter feet: ";  cin >> d2.feet;
   cout << "Enter inches: ";  cin >> d2.inches;
			       
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
