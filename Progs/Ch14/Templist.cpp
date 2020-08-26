// templist.cpp
// implements linked list as a template
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
template<class TYPE>                  //struct link<TYPE>
struct link                           //one element of list
//( within this struct def link means link<TYPE> )
   {
   TYPE data;                         //data item
   link* next;                        //pointer to next link
   };
////////////////////////////////////////////////////////////////
template<class TYPE>                  //class linklist<TYPE>
class linklist                        //a list of links
//(within this class, linklist means linklist<TYPE>)
   {
   private:
      link<TYPE>* first;              //pointer to first link
   public:
      linklist()                      //no-argument constructor
         { first = NULL; }            //no first link
      //note: destructor would be nice; not shown for simplicity   
      void additem(TYPE d);           //add data item (one link)
      void display();                 //display all links
   };
////////////////////////////////////////////////////////////////
template<class TYPE>
void linklist<TYPE>::additem(TYPE d)  //add data item
   {
   link<TYPE>* newlink = new link<TYPE>;  //make a new link
   newlink->data = d;                 //give it data
   newlink->next = first;             //it points to next link
   first = newlink;                   //now first points to this
   }
//--------------------------------------------------------------
template<class TYPE>
void linklist<TYPE>::display()        //display all links
   {
   link<TYPE>* current = first;       //set ptr to first link
   while( current != NULL )           //quit on last link
      {
      cout << endl << current->data;  //print data
      current = current->next;        //move to next link
      }
   }
//--------------------------------------------------------------
int main()
   {
   linklist<double> ld; //ld is object of class linklist<double>

   ld.additem(151.5);   //add three doubles to list ld
   ld.additem(262.6);
   ld.additem(373.7);
   ld.display();        //display entire list ld

   linklist<char> lch;  //lch is object of class linklist<char>

   lch.additem('a');    //add three chars to list lch
   lch.additem('b');
   lch.additem('c');
   lch.display();       //display entire list lch
   cout << endl;
   return 0;
   }
