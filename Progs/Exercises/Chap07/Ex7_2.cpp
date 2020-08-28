// ex7_2.cpp
// employee object uses a string as data
#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////
class employee
   {
   private:
      string name;
      long number;
   public:
      void getdata()          //get data from user
         {
         cout << "\nEnter name: ";  cin >> name;
         cout << "Enter number: "; cin >> number;
         }
      void putdata()          //display data
         {
         cout << "\n   Name: " << name;
         cout << "\n   Number: " << number;
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   employee emparr[100];      //an array of employees
   int n = 0;                 //how many employees
   char ch;                   //user response
                           
   do {                       //get data from user
      cout << "\nEnter data for employee number " << n+1;
      emparr[n++].getdata();
      cout << "Enter another (y/n)? "; cin >> ch;
      } while( ch != 'n' );
   
   for(int j=0; j<n; j++)     //display data in array
      {
      cout << "\nEmployee number " << j+1;
      emparr[j].putdata();
      }
   cout << endl;
   return 0;
   }