// deque.cpp
// demonstrates push_back(), push_front(), front()
#include <iostream>
#include <deque>
using namespace std;

int main()
   {
   deque<int> deq;

   deq.push_back(30);              // push items on back
   deq.push_back(40);
   deq.push_back(50);
   deq.push_front(20);             // push items on front
   deq.push_front(10);

   deq[2] = 33;                    // change middle item

   for(int j=0; j<deq.size(); j++)
      cout << deq[j] << ' ';       // display items
   cout << endl;
   return 0;
   }
