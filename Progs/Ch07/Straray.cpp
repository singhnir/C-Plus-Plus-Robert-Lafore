// straray.cpp
// array of strings
#include <iostream>
using namespace std;

int main()
   {
   const int DAYS = 7;          //number of strings in array
   const int MAX = 10;          //maximum size of each string
                                //array of strings
   char star[DAYS][MAX] = { "Sunday", "Monday", "Tuesday",
                            "Wednesday", "Thursday",
                            "Friday", "Saturday"  };			
   for(int j=0; j<DAYS; j++)    //display every string
      cout << star[j] << endl;
   return 0;
   }