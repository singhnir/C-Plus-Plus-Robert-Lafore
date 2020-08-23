// strpart.cpp
// string used in widget part object
#include <iostream>
#include <cstring>        //for strcpy()
using namespace std;
////////////////////////////////////////////////////////////////
class part
   {
   private:
      char partname[30];  //name of widget part
      int partnumber;     //ID number of widget part
      double cost;        //cost of part
   public:
      void setpart(char pname[], int pn, double c)
         {
         strcpy(partname, pname);
         partnumber = pn;
         cost = c;
         }
      void showpart()     //display data
         {
         cout << "\nName="   << partname;
         cout << ", number=" << partnumber;
         cout << ", cost=$"  << cost;
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   part part1, part2;                        
				      
   part1.setpart("handle bolt", 4473, 217.55);   //set parts
   part2.setpart("start lever", 9924, 419.25);
   cout << "\nFirst part: ";  part1.showpart();  //show parts
   cout << "\nSecond part: "; part2.showpart();
   cout << endl;
   return 0;
   }