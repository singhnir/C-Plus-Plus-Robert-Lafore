// statdata.cpp
// static class data
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class foo
   {
   private:
      static int count;   //only one data item for all objects
                          //note: *declaration* only!
   public:
      foo()               //increments count when object created
         { count++; }
      int getcount()      //returns count
         { return count; }
   };
//--------------------------------------------------------------
int foo::count = 0;       //*definition* of count
////////////////////////////////////////////////////////////////
int main()
   {
   foo f1, f2, f3;        //create three objects

   cout << "count is " << f1.getcount() << endl;  //each object
   cout << "count is " << f2.getcount() << endl;  //sees the
   cout << "count is " << f3.getcount() << endl;  //same value
   return 0;
   }