// strimem.cpp
// memory-saving String class
// overloaded assignment and copy constructor
#include <iostream>
#include <cstring>                //for strcpy(), etc.
using namespace std;
////////////////////////////////////////////////////////////////
class strCount                    //keep track of number
   {                              //of unique strings
   private:
      int count;                  //number of instances
      char* str;                  //pointer to string
      friend class String;        //make ourselves available
      //member functions are private                                             
//--------------------------------------------------------------
      strCount(char* s)           //one-arg constructor
         {
         int length = strlen(s);  //length of string argument
         str = new char[length+1];  //get memory for string
         strcpy(str, s);          //copy argument to it
         count=1;                 //start count at 1
         }
//--------------------------------------------------------------
      ~strCount()                 //destructor
         { delete[] str; }        //delete the string        
   };
////////////////////////////////////////////////////////////////
class String                      //String class
   {
   private:
      strCount* psc;              //pointer to strCount
   public:
      String()                    //no-arg constructor
         { psc = new strCount("NULL"); }
//--------------------------------------------------------------
      String(char* s)             //1-arg constructor
         { psc = new strCount(s); }
//--------------------------------------------------------------
      String(String& S)           //copy constructor
         {     
         psc = S.psc;
         (psc->count)++;
         }
//--------------------------------------------------------------
      ~String()                   //destructor
         {
         if(psc->count==1)        //if we are its last user,
            delete psc;           //   delete our strCount
         else                     //   otherwise,
            (psc->count)--;       //   decrement its count
         }
//--------------------------------------------------------------
      void display()              //display the String
         {
         cout << psc->str;                 //print string
         cout << " (addr=" << psc << ")";  //print address
         }
//--------------------------------------------------------------
      void operator = (String& S) //assign the string
         {
         if(psc->count==1)        //if we are its last user,
            delete psc;           //   delete our strCount
         else                     //   otherwise,
            (psc->count)--;       //   decrement its count
         psc = S.psc;             //use argument's strCount
         (psc->count)++;          //increment its count
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   String s3 = "When the fox preaches, look to your geese.";
   cout << "\ns3="; s3.display();   //display s3

   String s1;                       //define String
   s1 = s3;                         //assign it another String
   cout << "\ns1="; s1.display();   //display it

   String s2(s3);                   //initialize with String
   cout << "\ns2="; s2.display();   //display it
   cout << endl;
   return 0;
   }
