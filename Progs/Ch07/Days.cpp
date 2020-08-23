// days.cpp
// shows days from start of year to date specified
#include <iostream>
using namespace std;

int main()
   {
   int month, day, total_days;
   int days_per_month[12] = { 31, 28, 31, 30, 31, 30,
			      31, 31, 30, 31, 30, 31 };

   cout << "\nEnter month (1 to 12): ";  //get date
   cin >> month;
   cout << "Enter day (1 to 31): ";
   cin >> day;
   total_days = day;                     //separate days
   for(int j=0; j<month-1; j++)          //add days each month
      total_days += days_per_month[j];
   cout << "Total days from start of year is: " << total_days
        << endl;
   return 0;
   }