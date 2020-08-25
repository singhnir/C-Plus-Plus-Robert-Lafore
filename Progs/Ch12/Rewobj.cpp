// rewobj.cpp
// person objects do disk I/O
#include <fstream>               //for file streams
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class person                     //class of persons
   {
   protected:
      char name[40];             //person's name
      int age;                   //person's age
   public:
      void getData(void)         //get person's data
         {
         cout << "\n   Enter last name: "; cin >> name;
         cout << "   Enter age: "; cin >> age;
         }
      void showData(void)        //display person's data
         {
         cout << "\n   Name: " << name;
         cout << "\n   Age: " << age;
         }
      void diskIn(int);          //read from file
      void diskOut();            //write to file
      static int diskCount();    //return number of
                                 //   persons in file
   };
//--------------------------------------------------------------
void person::diskIn(int pn)      //read person number pn
   {                             //from file
   ifstream infile;                           //make stream
   infile.open("PERSFILE.DAT", ios::binary);  //open it
   infile.seekg( pn*sizeof(person) );         //move file ptr
   infile.read( (char*)this, sizeof(*this) ); //read one person
   }
//--------------------------------------------------------------
void person::diskOut()           //write person to end of file
   {
   ofstream outfile;             //make stream
                                 //open it
   outfile.open("PERSFILE.DAT", ios::app | ios::binary);
   outfile.write( (char*)this, sizeof(*this) ); //write to it
   }
//--------------------------------------------------------------
int person::diskCount()          //return number of persons
   {                             //in file
   ifstream infile;
   infile.open("PERSFILE.DAT", ios::binary);
   infile.seekg(0, ios::end);    //go to 0 bytes from end
                                 //calculate number of persons
   return (int)infile.tellg() / sizeof(person);
   }
////////////////////////////////////////////////////////////////
int main()
   {
   person p;                     //make an empty person
   char ch;
      
   do {                          //save persons to disk
      cout << "Enter data for person:";
      p.getData();               //get data
      p.diskOut();               //write to disk
      cout << "Do another (y/n)? ";
      cin >> ch;
      }  while(ch=='y');         //until user enters 'n'
   
   int n = person::diskCount();  //how many persons in file?
   cout << "There are " << n << " persons in file\n";
   for(int j=0; j<n; j++)        //for each one,
      {
      cout << "\nPerson " << j; 
      p.diskIn(j);               //read person from disk
      p.showData();              //display person
      }
   cout << endl;
   return 0;
   }