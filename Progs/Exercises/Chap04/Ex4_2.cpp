// ex4_2.cpp
// structure models point on the plane
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
struct point
   {
   int xCo;     //X coordinate
   int yCo;     //Y coordinate
   };
////////////////////////////////////////////////////////////////
int main()
   {
   point p1, p2, p3;                        //define 3 points

   cout << "\nEnter coordinates for p1: ";  //get 2 points
   cin >> p1.xCo >> p1.yCo;                 //from user
   cout << "Enter coordinates for p2: ";
   cin >> p2.xCo >> p2.yCo;

   p3.xCo = p1.xCo + p2.xCo;                //find sum of
   p3.yCo = p1.yCo + p2.yCo;                //p1 and p2

   cout << "Coordinates of p1+p2 are: "     //display the sum
	<< p3.xCo << ", " << p3.yCo << endl;
   return 0;
   }