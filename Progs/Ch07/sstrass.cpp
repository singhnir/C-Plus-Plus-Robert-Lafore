//sstrass.cpp
//defining and assigning string objects
#include <iostream>
#include <string>
using namespace std;

int main()
   {
   string s1("Man");                //initialize 
   string s2 = "Beast";             //initialize
   string s3;
   
   s3 = s1;                         //assign
   cout << "s3 = " << s3 << endl;

   s3 = "Neither " + s1 + " nor ";  //concatenate
   s3 += s2;                        //concatenate
   cout << "s3 = " << s3 << endl;

   s1.swap(s2);                     //swap s1 and s2
   cout << s1 << " nor " << s2 << endl;
   return 0;
   }