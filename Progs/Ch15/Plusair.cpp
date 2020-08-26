//plusair.cpp
//uses accumulate() algorithm and plus() function object
#include <iostream>
#include <list>
#include <numeric>          //for accumulate()
using namespace std;
////////////////////////////////////////////////////////////////
class airtime
   {
   private:
      int hours;            //0 to 23
      int minutes;          //0 to 59
   public:
                            //default constructor
      airtime() : hours(0), minutes(0)
         {  }
                            //2-arg constructor
      airtime(int h, int m) : hours(h), minutes(m)
         {  }
      void display() const  //output to screen
         { cout << hours << ':' << minutes; }

      void get()            //input from user
         {
         char dummy;
         cout << "\nEnter airtime (format 12:59): ";
         cin >> hours >> dummy >> minutes;
         }
                            //overloaded + operator
      airtime operator + (const airtime right) const
         {                  //add members
         int temph = hours + right.hours;
         int tempm = minutes + right.minutes;
         if(tempm >= 60)    //check for carry
            { temph++; tempm -= 60; }
         return airtime(temph, tempm); //return sum
         }
                            //overloaded == operator
      bool operator == (const airtime& at2) const
         { return (hours == at2.hours) && 
                  (minutes == at2.minutes); }
                            //overloaded < operator
      bool operator < (const airtime& at2) const
         { return (hours < at2.hours) || 
                  (hours == at2.hours && minutes < at2.minutes); }
                            //overloaded != operator
      bool operator != (const airtime& at2) const
         { return !(*this==at2); }
                            //overloaded > operator
      bool operator > (const airtime& at2) const
         { return !(*this<at2) && !(*this==at2); }
   };  //end class airtime
////////////////////////////////////////////////////////////////
int main()
   {
   char answer;
   airtime temp, sum;
   list<airtime> airlist;   //list of airtimes

   do {                     //get airtimes from user
      temp.get();
      airlist.push_back(temp);
      cout << "Enter another (y/n)? ";
      cin >> answer;
      } while (answer != 'n');
                            //sum all the airtimes
   sum = accumulate( airlist.begin(), airlist.end(),
                     airtime(0, 0), plus<airtime>() );
   cout << "\nsum = ";
   sum.display();           //display sum
   cout << endl;
   return 0;
   }

