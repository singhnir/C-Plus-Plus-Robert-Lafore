// englptr.cpp
// accessing member functions by pointer
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Distance              //English Distance class
   {
   private:
      int feet;
      float inches;
   public:
      void getdist()        //get length from user
         {
         cout << "\nEnter feet: ";  cin >> feet;
         cout << "Enter inches: ";  cin >> inches;
         }
      void showdist()       //display distance
         { cout << feet << "\'-" << inches << '\"'; }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   Distance dist;           //define a named Distance object
   dist.getdist();          //access object members 
   dist.showdist();         //   with dot operator

   Distance* distptr;       //pointer to Distance
   distptr = new Distance;  //points to new Distance object
   distptr->getdist();      //access object members 
   distptr->showdist();     //   with -> operator
   cout << endl;
   return 0;
   }