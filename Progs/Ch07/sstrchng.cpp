//sstrchng.cpp
//changing parts of string objects
#include <iostream>
#include <string>
using namespace std;

int main()
   {
   string s1("Quick! Send for Count Graystone.");
   string s2("Lord");
   string s3("Don't ");

   s1.erase(0, 7);               //remove "Quick! "
   s1.replace(9, 5, s2);         //replace "Count" with "Lord"
   s1.replace(0, 1, "s");        //replace 'S' with 's'
   s1.insert(0, s3);             //insert "Don't " at beginning
   s1.erase(s1.size()-1, 1);     //remove '.'
   s1.append(3, '!');            //append "!!!"

   int x = s1.find(' ');         //find a space
   while( x < s1.size() )        //loop while spaces remain
      {
      s1.replace(x, 1, "/");     //replace with slash
      x = s1.find(' ');          //find next space
      }
   cout << "s1: " << s1 << endl;
   return 0;
   }