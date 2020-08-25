// xofxref.cpp
// copy constructor: X(X&)
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class alpha
   {
   private:
      int data;
   public:
      alpha()                    //no-arg constructor
         { }
      alpha(int d)               //one-arg constructor
         { data = d; }
      alpha(alpha& a)            //copy constructor
         {
         data = a.data;
         cout << "\nCopy constructor invoked";
         }
      void display()             //display
         { cout << data; }
      void operator = (alpha& a) //overloaded = operator
         {
         data = a.data;
         cout << "\nAssignment operator invoked";
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   alpha a1(37);
   alpha a2;

   a2 = a1;                        //invoke overloaded =
   cout << "\na2="; a2.display();  //display a2

   alpha a3(a1);                   //invoke copy constructor
// alpha a3 = a1;                  //equivalent definition of a3
   cout << "\na3="; a3.display();  //display a3
   cout << endl;
   return 0;
   }
