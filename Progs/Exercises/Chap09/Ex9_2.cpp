// ex9_2.cpp
//inheritance from String class
#include <iostream>
#include <cstring>                //for strcpy(), etc.
using namespace std;               
////////////////////////////////////////////////////////////////
class String                      //base class
   {
   protected:                     //Note: can't be private
      enum { SZ = 80 };           //size of all String objects
      char str[SZ];               //holds a C-string
   public:
      String()                    //constructor 0, no args
         { str[0] = '\0'; }
      String( char s[] )          //constructor 1, one arg
         { strcpy(str, s); }      //  convert string to String
      void display() const        //display the String
         { cout << str; }
      operator char*()            //conversion function
         { return str; }          //convert String to C-string
   };
////////////////////////////////////////////////////////////////
class Pstring : public String     //derived class 
   {
   public:
      Pstring( char s[] );        //constructor
   };
//--------------------------------------------------------------
Pstring::Pstring( char s[] )      //constructor for Pstring
   {
   if(strlen(s) > SZ-1)           //if too long,
      {
      for(int j=0; j<SZ-1; j++)   //copy the first SZ-1
         str[j] = s[j];           //characters "by hand"
      str[j] = '\0';              //add the null character
      }
   else                           //not too long,
      String(s);                  //so construct normally
   }
////////////////////////////////////////////////////////////////
int main()
   {                                        //define String
   Pstring s1 = "This is a very long string which is probably "
          "no, certainly--going to exceed the limit set by SZ.";
   cout << "\ns1="; s1.display();           //display String

   Pstring s2 = "This is a short string.";  //define String
   cout << "\ns2="; s2.display();           //display String
   cout << endl;
   return 0;
   }
