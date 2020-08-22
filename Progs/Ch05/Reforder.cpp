// reforder.cpp
// orders two arguments passed by reference
#include <iostream>
using namespace std;

int main()
   {
   void order(int&, int&);          //prototype

   int n1=99, n2=11;                //this pair not ordered
   int n3=22, n4=88;                //this pair ordered

   order(n1, n2);                   //order each pair of numbers
   order(n3, n4);

   cout << "n1=" << n1 << endl;     //print out all numbers
   cout << "n2=" << n2 << endl;
   cout << "n3=" << n3 << endl;
   cout << "n4=" << n4 << endl;
   return 0;
   }
//--------------------------------------------------------------
void order(int& numb1, int& numb2)  //orders two numbers
   {
   if(numb1 > numb2)                //if 1st larger than 2nd,
      {
      int temp = numb1;             //swap them
      numb1 = numb2;
      numb2 = temp;
      }
   }