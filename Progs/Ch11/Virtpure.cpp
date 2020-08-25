// virtpure.cpp
// pure virtual function
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Base                        //base class
   {
   public:
      virtual void show() = 0;    //pure virtual function
   };
////////////////////////////////////////////////////////////////
class Derv1 : public Base         //derived class 1
   {
   public:
      void show()
         { cout << "Derv1\n"; }
   };
////////////////////////////////////////////////////////////////
class Derv2 : public Base         //derived class 2
   {
   public:
      void show()
         { cout << "Derv2\n"; }
   };
////////////////////////////////////////////////////////////////
int main()
   {
// Base bad;            //can't make object from abstract class
   Base* arr[2];        //array of pointers to base class
   Derv1 dv1;           //object of derived class 1
   Derv2 dv2;           //object of derived class 2

   arr[0] = &dv1;       //put address of dv1 in array
   arr[1] = &dv2;       //put address of dv2 in array

   arr[0]->show();      //execute show() in both objects
   arr[1]->show();
   return 0;
   }