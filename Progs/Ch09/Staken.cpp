// staken.cpp
// overloading functions in base and derived classes
#include <iostream>
using namespace std;
#include <process.h>            //for exit()
////////////////////////////////////////////////////////////////
class Stack
   {
   protected:                   //NOTE: can't be private
      enum { MAX = 3 };         //size of stack array
      int st[MAX];              //stack: array of integers
      int top;                  //index to top of stack
   public:
      Stack()                   //constructor
         { top = -1; }
      void push(int var)        //put number on stack
         { st[++top] = var; }
      int pop()                 //take number off stack
         { return st[top--]; }
   };
////////////////////////////////////////////////////////////////
class Stack2 : public Stack
   {
   public:
      void push(int var)        //put number on stack
         {
         if(top >= MAX-1)	     //error if stack full
            { cout << "\nError: stack is full"; exit(1); }
         Stack::push(var);      //call push() in Stack class
         }
      int pop()                 //take number off stack
         {
         if(top < 0)            //error if stack empty
            { cout << "\nError: stack is empty\n"; exit(1); }
         return Stack::pop();   //call pop() in Stack class
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   Stack2 s1;

   s1.push(11);                 //push some values onto stack
   s1.push(22);
   s1.push(33);

   cout << endl << s1.pop();    //pop some values from stack
   cout << endl << s1.pop();
   cout << endl << s1.pop();
   cout << endl << s1.pop();    //oops, popped one too many...
   cout << endl;
   return 0;
   }
