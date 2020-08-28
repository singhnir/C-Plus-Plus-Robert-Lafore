// ex6_1.cpp
// uses a class to model an integer data type
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Int                       //(not the same as int)
   {
   private:
      int i;
   public:
      Int()                     //create an Int
         { i = 0; }
      Int(int ii)               //create and initialize an Int
         { i = ii; }
      void add(Int i2, Int i3)  //add two Ints
         { i = i2.i + i3.i; }
      void display()            //display an Int
         { cout << i; }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   Int Int1(7);                 //create and initialize an Int
   Int Int2(11);                //create and initialize an Int
   Int Int3;                    //create an Int

   Int3.add(Int1, Int2);                 //add two Ints
   cout << "\nInt3 = "; Int3.display();  //display result
   cout << endl;
   return 0;
   }