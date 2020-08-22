// retstrc.cpp
// demonstrates returning a structure
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
struct Distance                        //English distance
   {
   int feet;
   float inches;
   };
////////////////////////////////////////////////////////////////
Distance addengl(Distance, Distance);  //declarations
void engldisp(Distance);

int main()
   {
   Distance d1, d2, d3;                //define three lengths
                                       //get length d1 from user
   cout << "\nEnter feet: ";  cin >> d1.feet;
   cout << "Enter inches: ";  cin >> d1.inches;
                                       //get length d2 from user
   cout << "\nEnter feet: ";  cin >> d2.feet;
   cout << "Enter inches: ";  cin >> d2.inches;

   d3 = addengl(d1, d2);               //d3 is sum of d1 and d2
   cout << endl;			       
   engldisp(d1); cout << " + ";        //display all lengths
   engldisp(d2); cout << " = ";
   engldisp(d3); cout << endl;
   return 0;
   }
//--------------------------------------------------------------
// addengl()
// adds two structures of type Distance, returns sum
Distance addengl( Distance dd1, Distance dd2 )
   {
   Distance dd3;                //define a new structure for sum

   dd3.inches = dd1.inches + dd2.inches;  //add the inches
   dd3.feet = 0;                       //(for possible carry)
   if(dd3.inches >= 12.0)              //if inches >= 12.0,
      {                                //then decrease inches
      dd3.inches -= 12.0;              //by 12.0 and
      dd3.feet++;                      //increase feet
      }                                //by 1
   dd3.feet += dd1.feet + dd2.feet;    //add the feet
   return dd3;                         //return structure
   }
//--------------------------------------------------------------
// engldisp()
// display structure of type Distance in feet and inches
void engldisp( Distance dd )   
   {
   cout << dd.feet << "\'-" << dd.inches << "\"";
   }
