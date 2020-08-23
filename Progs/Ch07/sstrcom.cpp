//sstrcom.cpp
//comparing string objects 
#include <iostream>
#include <string>
using namespace std;

int main()
   {
   string aName = "George";
   string userName;
   
   cout << "Enter your first name: ";
   cin >> userName;
   if(userName==aName)                   //operator ==
      cout << "Greetings, George\n";
   else if(userName < aName)             //operator <
      cout << "You come before George\n";
   else                     
      cout << "You come after George\n";
                                         //compare() function
   int n = userName.compare(0, 2, aName, 0, 2);
   cout << "The first two letters of your name ";
   if(n==0)
      cout << "match ";
   else if(n < 0)
      cout << "come before ";
   else
      cout << "come after ";
   cout << aName.substr(0, 2) << endl;
   return 0;
   }