// ex14_3.cpp
// implements queue class as a template
// uses exceptions to handle errors in queue
#include <iostream>
using namespace std;
const int MAX = 3;
////////////////////////////////////////////////////////////////
template <class Type>
class Queue
   {
   private:
		Type qu[MAX]; //array of any type
      int head;     //index of front of queue (remove old item)
      int tail;     //index of back of queue (insert new item)
      int count;    //number of items in queue
   public:
      class full  {  };          //exception classes
      class empty  {  };
//--------------------------------------------------------------
		Queue()                    //constructor
			{ head = -1; tail = -1; count = 0; }

      void put(Type var)         //insert item at queue tail
			{
         if(count >= MAX)        //if queue already full,
            throw full();        //   throw exception
         qu[++tail] = var;       //store item
         ++count;
         if(tail >=MAX-1)        //wrap around if past array end
            tail = -1;
         }
//--------------------------------------------------------------
      Type get()                 //remove item from queue head
         {
         if(count <= 0)          //if queue empty,
            throw empty();       //   throw exception
         Type temp = qu[++head]; //get item
         --count;
         if(head >= MAX-1)       //wrap around if past array end
            head = -1;
         return temp;            //return item
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   Queue<float> q1;     //q1 is object of class Queue<float>
   float data;          //data item obtained from user
   char choice = 'p';   //'x', 'p' or 'g'

   do                   //do loop (enter 'x' to quit)
      {
      try               //try block
         {
         cout << "\nEnter 'x' to exit, 'p' for put, 'g' for get: ";
         cin >> choice;
         if(choice=='p')
            {
            cout << "Enter data value: ";
            cin >> data;
            q1.put(data);
            }
         if(choice=='g')
            cout << "Data=" << q1.get() << endl;
         }  //end try
      catch(Queue<float>::full)
         {
         cout << "Error: queue is full." << endl;
         }
      catch(Queue<float>::empty)
         {
         cout << "Error: queue is empty." << endl;
         }
      } while(choice != 'x');
   return 0;
 	}  //end main()


