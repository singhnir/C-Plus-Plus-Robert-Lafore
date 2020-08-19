// increm.cpp
// demonstrates the increment operator
#include <iostream>
using namespace std;

int main()
   {
   int count = 10;

   cout << "count=" << count << endl;    //displays 10
   cout << "count=" << ++count << endl;  //displays 11 (prefix)
   cout << "count=" << count << endl;    //displays 11
   cout << "count=" << count++ << endl;  //displays 11 (postfix)
   cout << "count=" << count << endl;    //displays 12
   return 0;
   }