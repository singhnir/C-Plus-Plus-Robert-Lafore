// xstak2.cpp
// demonstrates two exception handlers
#include <iostream>
using namespace std;
const int MAX = 3;              //stack holds 3 ints
////////////////////////////////////////////////////////////////
class Stack
   {
   private:
      int st[MAX];              //stack: array of integers
      int top;                  //index of top of stack
   public:
      class Full { };           //exception class
      class Empty { };          //exception class
//--------------------------------------------------------------
      Stack()                   //constructor
	      { top = -1; }
//--------------------------------------------------------------
      void push(int var)        //put number on stack
	      {
         if(top >= MAX-1)       //if stack full,
            throw Full();       //throw Full exception
         st[++top] = var;
         }
//--------------------------------------------------------------
      int pop()                 //take number off stack
	      {
         if(top < 0)            //if stack empty,
            throw Empty();      //throw Empty exception
         return st[top--];
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   Stack s1;

   try
      {
      s1.push(11);
      s1.push(22);
      s1.push(33);
//    s1.push(44);                        //oops: stack full
      cout << "1: " << s1.pop() << endl;
      cout << "2: " << s1.pop() << endl;
      cout << "3: " << s1.pop() << endl;
      cout << "4: " << s1.pop() << endl;  //oops: stack empty
      }
   catch(Stack::Full)
      {
      cout << "Exception: Stack Full" << endl;
      }
   catch(Stack::Empty)
      {
      cout << "Exception: Stack Empty" << endl;
      }
   return 0;
   }

