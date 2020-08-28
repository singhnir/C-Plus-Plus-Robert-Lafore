// ex6_3.cpp
// uses class to model a time data type
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class time
   {
   private:
      int hrs, mins, secs;
   public:
      time() : hrs(0), mins(0), secs(0) //no-arg constructor
         {  }
                                        //3-arg constructor
      time(int h, int m, int s) : hrs(h), mins(m), secs(s)         
         {  }

      void display() const              //format 11:59:59
         { cout << hrs << ":" << mins << ":" << secs; }

      void add_time(time t1, time t2)   //add two times
         {
         secs = t1.secs + t2.secs;      //add seconds
         if( secs > 59 )                //if overflow,
            { secs -= 60; mins++; }     //   carry a minute
         mins += t1.mins + t2.mins;     //add minutes
         if( mins > 59 )                //if overflow,
            { mins -= 60; hrs++; }      //   carry an hour
         hrs += t1.hrs + t2.hrs;        //add hours
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   const time time1(5, 59, 59);         //creates and initialze
   const time time2(4, 30, 30);         //   two times
   time time3;                          //create another time

   time3.add_time(time1, time2);        //add two times
   cout << "time3 = "; time3.display(); //display result
   cout << endl;
   return 0;
   }