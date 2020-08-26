// tempstak.cpp
// implements stack class as a template
#include <iostream>
using namespace std;
const int MAX = 100;
////////////////////////////////////////////////////////////////
template <class Type>
class Stack
   {
   private:
		Type st[MAX];             //stack: array of any type
      int top;                  //number of top of stack
   public:
		Stack()                   //constructor
			{ top = -1; }
      void push(Type var)       //put number on stack
			{ st[++top] = var; }
      Type pop()                //take number off stack
         { return st[top--]; }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   Stack<float> s1;      //s1 is object of class Stack<float>

   s1.push(1111.1F);     //push 3 floats, pop 3 floats
   s1.push(2222.2F);
   s1.push(3333.3F);
   cout << "1: " << s1.pop() << endl;
   cout << "2: " << s1.pop() << endl;
   cout << "3: " << s1.pop() << endl;

   Stack<long> s2;       //s2 is object of class Stack<long>

   s2.push(123123123L);  //push 3 longs, pop 3 longs
   s2.push(234234234L);
   s2.push(345345345L);
   cout << "1: " << s2.pop() << endl;
   cout << "2: " << s2.pop() << endl;
   cout << "3: " << s2.pop() << endl;
   return 0;
	}


