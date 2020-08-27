// ex4_3.cpp
// uses structure to model volume of room
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
struct Distance
   {
   int feet;
   float inches;
   };
////////////////////////////////////////////////////////////////
struct Volume
   {
   Distance length;
   Distance width;
   Distance height;
   };
////////////////////////////////////////////////////////////////
int main()
   {
   float l, w, h;
   Volume room1 = {  { 16, 3.5 }, { 12, 6.25 }, { 8, 1.75 } };

   l = room1.length.feet + room1.length.inches/12.0;
   w = room1.width.feet  + room1.width.inches /12.0;
   h = room1.height.feet + room1.height.inches/12.0;

   cout << "Volume = " << l*w*h << " cubic feet\n";
   return 0;
   }