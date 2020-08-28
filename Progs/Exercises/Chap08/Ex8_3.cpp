// ex8_3.cpp
// overloaded '+' operator adds two times
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class time
   {
   private:
      int hrs, mins, secs;
   public:
      time() : hrs(0), mins(0), secs(0) //no-arg constructor
         {  }                           //3-arg constructor
      time(int h, int m, int s) : hrs(h), mins(m), secs(s)       
         {  }
      void display()                    //format 11:59:59
         { cout << hrs << ":" << mins << ":" << secs; }

      time operator + (time t2)         //add two times
         {
         int s = secs + t2.secs;        //add seconds
         int m = mins + t2.mins;        //add minutes
         int h = hrs + t2.hrs;          //add hours
         if( s > 59 )                   //if secs overflow,
            { s -= 60; m++; }           //   carry a minute
         if( m > 59 )                   //if mins overflow,
            { m -= 60; h++; }           //   carry an hour
         return time(h, m, s);          //return temp value
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   time time1(5, 59, 59);               //create and initialze
   time time2(4, 30, 30);               //   two times
   time time3;                          //create another time

   time3 = time1 + time2;               //add two times
   cout << "\ntime3 = "; time3.display(); //display result
   cout << endl;
   return 0;
   }