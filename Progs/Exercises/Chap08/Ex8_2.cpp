// ex8_2.cpp
// overloaded '+=' operator concatenates strings
#include <iostream>
#include <cstring>       //for strcpy(), strlen()
using namespace std;
#include <process.h>     //for exit()
////////////////////////////////////////////////////////////////
class String             //user-defined string type
   {
   private:
      enum { SZ = 80 };              //size of String objects
      char str[SZ];                  //holds a C-string
   public:
      String()                       //no-arg constructor
         { strcpy(str, ""); }
      String( char s[] )             //1-arg constructor
         { strcpy(str, s); }
      void display()                 //display the String
         { cout << str; }
      String operator += (String ss) //add a String to this one
         {                           //result stays in this one
         if( strlen(str) + strlen(ss.str) >= SZ )
            { cout << "\nString overflow"; exit(1); }
         strcat(str, ss.str);        //add the argument string
         return String(str);         //return temp String
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   String s1 = "Merry Christmas!  ";      //uses 1-arg ctor
   String s2 = "Happy new year!";         //uses 1-arg ctor
   String s3;                             //uses no-arg ctor

   s3 = s1 += s2;         //add s2 to s1, assign to s3

   cout << "\ns1="; s1.display();         //display s1
   cout << "\ns2="; s2.display();         //display s2
   cout << "\ns3="; s3.display();         //display s3
   cout << endl;
   return 0;
   }
