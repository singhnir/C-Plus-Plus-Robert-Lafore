// ex6_2.cpp
// uses class to model toll booth
#include <iostream>
using namespace std;
#include <conio.h>

const char ESC = 27;           //escape key ASCII code
const double TOLL = 0.5;       //toll is 50 cents
////////////////////////////////////////////////////////////////
class tollBooth
   {
   private:
      unsigned int totalCars;  //total cars passed today
      double totalCash;        //total money collected today
   public:                     //constructor
      tollBooth() : totalCars(0), totalCash(0.0)                              
         {  }
      void payingCar()                       //a car paid
         { totalCars++; totalCash += TOLL; }
      void nopayCar()                        //a car didn't pay
         { totalCars++; }
      void display() const                   //display totals
         { cout << "\nCars=" << totalCars
                << ", cash=" << totalCash
                << endl; }
    };
////////////////////////////////////////////////////////////////
int main()
   {
   tollBooth booth1;           //create a toll booth
   char ch;

   cout << "\nPress 0 for each non-paying car,"
        << "\n      1 for each paying car,"
        << "\n      Esc to exit the program.\n";   
   do {
      ch = getche();           //get character
      if( ch == '0' )          //if it's 0, car didn't pay
         booth1.nopayCar();
      if( ch == '1' )          //if it's 1, car paid
         booth1.payingCar();
      } while( ch != ESC );    //exit loop on Esc key
   booth1.display();           //display totals
   return 0;
   }