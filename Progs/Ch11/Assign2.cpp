//assign2.cpp
// returns contents of the this pointer
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class alpha
   {
   private:
      int data;
   public:
      alpha()                      //no-arg constructor
         { }
      alpha(int d)                 //one-arg constructor
         { data = d; }
      void display()               //display data
         { cout << data; }
      alpha& operator = (alpha& a) //overloaded = operator
         {
         data = a.data;            //not done automatically
         cout << "\nAssignment operator invoked";
         return *this;             //return copy of this alpha
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   alpha a1(37);
   alpha a2, a3;

   a3 = a2 = a1;                   //invoke overloaded =, twice
   cout << "\na2="; a2.display();  //display a2
   cout << "\na3="; a3.display();  //display a3
   cout << endl;
   return 0;
   }