// ex5_1.cpp
// function finds area of circle
#include <iostream>
using namespace std;
float circarea(float radius);

int main()
   {
   double rad;
   cout << "\nEnter radius of circle: ";
   cin >> rad;
   cout << "Area is " << circarea(rad) << endl;
   return 0;
   }
//--------------------------------------------------------------
float circarea(float r)
   {
   const float PI = 3.14159F;
   return r * r * PI;
   }