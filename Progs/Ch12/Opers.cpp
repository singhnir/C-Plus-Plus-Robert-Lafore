// opers.cpp
// saves person object to disk
#include <fstream>                //for file streams
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class person                      //class of persons
   {
   protected:
      char name[80];              //person's name
      short age;                  //person's age
   public:
      void getData()              //get person's data
         {
         cout << "Enter name: "; cin >> name;
         cout << "Enter age: "; cin >> age;
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   person pers;                   //create a person
   pers.getData();                //get data for person
                                  //create ofstream object
   ofstream outfile("PERSON.DAT", ios::binary);
                                  //write to it
   outfile.write(reinterpret_cast<char*>(&pers), sizeof(pers));  
   return 0;
   }