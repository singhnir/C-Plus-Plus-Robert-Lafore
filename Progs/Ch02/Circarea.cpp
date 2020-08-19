// circarea.cpp
// demonstrates floating point variables
#include <iostream>                     //for cout, etc.
using namespace std;

int main()
   {
   float rad;                           //variable of type float
   const float PI = 3.14159F;           //type const float

   cout << "Enter radius of circle: ";  //prompt
   cin >> rad;                          //get radius
   float area = PI * rad * rad;         //find area
   cout << "Area is " << area << endl;  //display answer
   return 0;
   }