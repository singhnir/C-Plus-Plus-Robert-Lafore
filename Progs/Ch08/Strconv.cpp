// strconv.cpp
// convert between ordinary strings and class String
#include <iostream>
using namespace std;
#include <string.h>             //for strcpy(), etc.
////////////////////////////////////////////////////////////////
class String                    //user-defined string type
   {
   private:
      enum { SZ = 80 };         //size of all String objects
      char str[SZ];             //holds a C-string
   public:
      String()                  //no-arg constructor
         { str[0] = '\0'; }
      String( char s[] )        //1-arg constructor
         { strcpy(str, s); }    //   convert C-string to String
      void display() const      //display the String
         { cout << str; }
      operator char*()          //conversion operator
         { return str; }        //convert String to C-string
   };
////////////////////////////////////////////////////////////////
int main()
   {
   String s1;                   //use no-arg constructor
                                //create and initialize C-string
   char xstr[] = "Joyeux Noel! ";

   s1 = xstr;                   //use 1-arg constructor
                                //   to convert C-string to String
   s1.display();                //display String

   String s2 = "Bonne Annee!";  //uses 1-arg constructor
                                //to initialize String
   cout << static_cast<char*>(s2); //use conversion operator
	cout << endl;	              //to convert String to C-string
	return 0;			           //before sending to << op
   }
