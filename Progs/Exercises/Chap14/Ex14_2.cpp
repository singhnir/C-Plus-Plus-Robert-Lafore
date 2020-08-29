// ex14_2.cpp
// implements queue class as a template
#include <iostream>
using namespace std;
const int MAX = 3;
////////////////////////////////////////////////////////////////
template <class Type>
class Queue
   {
   private:
		Type qu[MAX]; //array of any type
      int head;     //index of start of queue (remove item here)
      int tail;     //index of end of queue (insert item here)
   public:
		Queue()                    //constructor
			{ head = -1; tail = -1; }
      void put(Type var)         //insert item at queue tail
			{
         qu[++tail] = var;
         if(tail >=MAX-1)        //wrap around if past array end
            tail = -1;
         }
      Type get()                 //remove item from queue head
         {
         Type temp = qu[++head]; //store item
         if(head >= MAX-1)       //wrap around if past array end
            head = -1;
         return temp;            //return item
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   Queue<float> q1;     //q1 is object of class Queue<float>

   q1.put(1111.1F);                     //put 3
   q1.put(2222.2F);
   q1.put(3333.3F);
   cout << "1: " << q1.get() << endl;   //get 2
   cout << "2: " << q1.get() << endl;
   q1.put(4444.4F);                     //put 2
   q1.put(5555.5F);
   cout << "3: " << q1.get() << endl;   //get 1
   q1.put(6666.6F);                     //put 1
   cout << "4: " << q1.get() << endl;   //get 3
   cout << "5: " << q1.get() << endl;
   cout << "6: " << q1.get() << endl;

   Queue<long> q2;      //q2 is object of class Queue<long>

   q2.put(123123123L);  //put 3 longs, get 3 longs
   q2.put(234234234L);
   q2.put(345345345L);
   cout << "1: " << q2.get() << endl;
   cout << "2: " << q2.get() << endl;
   cout << "3: " << q2.get() << endl;
   return 0;
	}


