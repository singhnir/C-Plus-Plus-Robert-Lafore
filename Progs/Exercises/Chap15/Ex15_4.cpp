// ex15_4.cpp
// a multiset automatically sorts person objects stored by pointer
#include <iostream>
#include <set>
#pragma warning (disable:4786)
#include <string>
using namespace std;

class person
   {
   private:
      string lastName;
      string firstName;
      long phoneNumber;
   public:
      person() :             // default constructor
           lastName("blank"), firstName("blank"), phoneNumber(0L)
         {  }
                             // 3-arg constructor
      person(string lana, string fina, long pho) :
              lastName(lana), firstName(fina), phoneNumber(pho)
         {  }
      friend bool operator<(const person&, const person&);

      void display() const   // display person's data
         {
         cout << endl << lastName << ",\t" << firstName
              << "\t\tPhone: " << phoneNumber;
         }
      long get_phone() const // return phone number
         { return phoneNumber; }
   }; //end class person
//--------------------------------------------------------------
// overloaded < for person class
bool operator<(const person& p1, const person& p2)
   {
   if(p1.lastName == p2.lastName)
      return (p1.firstName < p2.firstName) ? true : false;
   return (p1.lastName < p2.lastName) ? true : false;
   }
//--------------------------------------------------------------
// function object to compare persons using pointers
class comparePersons
   {
   public:
   bool operator() (const person* ptrP1, 
                    const person* ptrP2) const
      { return *ptrP1 < *ptrP2; }
   };
////////////////////////////////////////////////////////////////
int main()
   {                          // a multiset of ptrs to persons
   multiset<person*, comparePersons> setPtrsPers;
   multiset<person*, comparePersons>::iterator iter;

                              //make persons
   person* ptrP1 = new person("KuangThu", "Bruce", 4157300);
   person* ptrP2 = new person("McDonald", "Stacey", 3327563);
   person* ptrP3 = new person("Deauville", "William", 8435150);
   person* ptrP4 = new person("Wellington", "John", 9207404);
   person* ptrP5 = new person("Bartoski", "Peter", 6946473);
   person* ptrP6 = new person("McDonald", "Amanda", 8435150);
   person* ptrP7 = new person("Fredericks", "Roger", 7049982);
   person* ptrP8 = new person("McDonald", "Stacey", 7764987);

   setPtrsPers.insert(ptrP1);         //put persons in multiset
   setPtrsPers.insert(ptrP2);
   setPtrsPers.insert(ptrP3);
   setPtrsPers.insert(ptrP4);
   setPtrsPers.insert(ptrP5);
   setPtrsPers.insert(ptrP6);
   setPtrsPers.insert(ptrP7);
   setPtrsPers.insert(ptrP8);
                                       //display multiset
   cout << "\n\nSet sorted when created:";
   for(iter=setPtrsPers.begin(); iter != setPtrsPers.end(); iter++ )
      (**iter).display();

   iter = setPtrsPers.begin();         //delete all persons          
   while( iter != setPtrsPers.end() )               
      {
      delete *iter;                    //delete person
      setPtrsPers.erase(iter++);       //remove pointer
      }
   cout << endl;
   return 0;
   }  // end main()
