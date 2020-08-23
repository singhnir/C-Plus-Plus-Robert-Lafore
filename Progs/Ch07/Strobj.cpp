// strobj.cpp
// a string as a class
#include <iostream>
#include <cstring>       // for strcpy(), strcat()
using namespace std;
////////////////////////////////////////////////////////////////
class String
   {
   private:
      enum { SZ = 80 };                  //max size of Strings
      char str[SZ];                      //array
   public:
      String()                           //constructor, no args
         { str[0] = '\0'; }
      String( char s[] )                 //constructor, one arg
         { strcpy(str, s); }
      void display()                     //display string
         { cout << str; }
      void concat(String s2)             //add arg string to
         {                               //this string
         if( strlen(str)+strlen(s2.str) < SZ )
            strcat(str, s2.str);
         else
            cout << "\nString too long";
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   String s1("Merry Christmas!  ");      //uses constructor 2
   String s2 = "Season's Greetings!";    //alternate form of 2
   String s3;                            //uses constructor 1

   cout << "\ns1="; s1.display();        //display them all
   cout << "\ns2="; s2.display();
   cout << "\ns3="; s3.display();

   s3 = s1;                              //assignment
   cout << "\ns3="; s3.display();        //display s3

   s3.concat(s2);                        //concatenation
   cout << "\ns3="; s3.display();        //display s3
   cout << endl;
   return 0;
   }