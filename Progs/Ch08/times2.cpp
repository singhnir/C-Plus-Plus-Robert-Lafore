//times2.cpp
//converts from time24 to time12 using constructor in time12
#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////
class time24
   {
   private:
      int hours;                     //0 to 23
      int minutes;                   //0 to 59
      int seconds;                   //0 to 59
   public:                           //no-arg constructor
      time24() : hours(0), minutes(0), seconds(0)
         {  }
      time24(int h, int m, int s) :  //3-arg constructor
              hours(h), minutes(m), seconds(s)
         {  }
      void display() const           //format 23:15:01
         {
         if(hours < 10)    cout << '0';
         cout << hours << ':';
         if(minutes < 10)  cout << '0';
         cout << minutes << ':';
         if(seconds < 10)  cout << '0';
         cout << seconds;
         }
      int getHrs() const   { return hours; }
      int getMins() const  { return minutes; }
      int getSecs() const  { return seconds; }
   };
////////////////////////////////////////////////////////////////
class time12
   {
   private:
      bool pm;                       //true = pm, false = am
      int hrs;                       //1 to 12
      int mins;                      //0 to 59
   public:                           //no-arg constructor
      time12() : pm(true), hrs(0), mins(0)
         {  }
      time12(time24);                //1-arg constructor
                                     //3-arg constructor
      time12(bool ap, int h, int m) : pm(ap), hrs(h), mins(m)
         {  }
      void display() const
         {
         cout << hrs << ':';
         if(mins < 10)  cout << '0';  //extra zero for "01"             
         cout << mins << ' ';
         string am_pm = pm ? "p.m." : "a.m.";
         cout << am_pm;
         }
   };
//--------------------------------------------------------------
time12::time12( time24 t24 )         //1-arg constructor
   {                                 //converts time24 to time12
   int hrs24 = t24.getHrs();         //get hours
                                     //find am/pm
   pm = t24.getHrs() < 12 ? false : true;
                                                      
   mins = (t24.getSecs() < 30) ?     //round secs
                         t24.getMins() : t24.getMins()+1;
   if(mins == 60)                    //carry mins?
      {
      mins=0;
      ++hrs24;
      if(hrs24 == 12 || hrs24 == 24)      //carry hrs?
         pm = (pm==true) ? false : true;  //toggle am/pm
      }
   hrs = (hrs24 < 13) ? hrs24 : hrs24-12; //convert hrs
   if(hrs==0)                        //00 is 12 a.m.
      { hrs=12; pm=false; }
   }
////////////////////////////////////////////////////////////////
int main()
   {
   int h, m, s;

   while(true)
      {                              //get 24-hour time from user
      cout << "Enter 24-hour time: \n";
      cout << "   Hours (0 to 23): "; cin >> h;
      if(h > 23)                     //quit if hours > 23
         return(1);
      cout << "   Minutes: ";  cin >> m;
      cout << "   Seconds: ";  cin >> s;

      time24 t24(h, m, s);           //make a time24
      cout << "You entered: ";       //display the time24
      t24.display();

      time12 t12 = t24;              //convert time24 to time12

      cout << "\n12-hour time: ";    //display equivalent time12
      t12.display();             
      cout << "\n\n";
      }
   return 0;
   }