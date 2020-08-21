// englstrc.cpp
// demonstrates structures using English measurements
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
struct Distance                //English distance
   {
   int feet;
   float inches;
   };
////////////////////////////////////////////////////////////////
int main()
   {
   Distance d1, d3;            //define two lengths
   Distance d2 = { 11, 6.25 }; //define & initialize one length

                               //get length d1 from user
   cout << "\nEnter feet: ";  cin >> d1.feet;
   cout << "Enter inches: ";  cin >> d1.inches;

                               //add lengths d1 and d2 to get d3
   d3.inches = d1.inches + d2.inches;  //add the inches
   d3.feet = 0;                //(for possible carry)
   if(d3.inches >= 12.0)       //if total exceeds 12.0,
      {                        //then decrease inches by 12.0
      d3.inches -= 12.0;       //and
      d3.feet++;               //increase feet by 1
      }                        
   d3.feet += d1.feet + d2.feet;  //add the feet

                               //display all lengths
   cout << d1.feet << "\'-" << d1.inches << "\" + ";
   cout << d2.feet << "\'-" << d2.inches << "\" = ";
   cout << d3.feet << "\'-" << d3.inches << "\"\n";
   return 0;
   }
