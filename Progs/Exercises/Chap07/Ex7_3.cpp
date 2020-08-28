// ex7_3.cpp
// averages an array of Distance objects input by user
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Distance                    // English Distance class
   {
   private:
      int feet;
      float inches;
   public:
      Distance()                  //constructor (no args)
         { feet = 0; inches = 0; }
      Distance(int ft, float in)  //constructor (two args)
         { feet = ft; inches = in; }

      void getdist()              //get length from user
         {
         cout << "\nEnter feet: ";  cin >> feet;
         cout << "Enter inches: ";  cin >> inches;
         }

      void showdist()             //display distance
         { cout << feet << "\'-" << inches << '\"'; }

      void add_dist( Distance, Distance );    //declarations
      void div_dist( Distance, int );
   };
//--------------------------------------------------------------
				  //add Distances d2 and d3
void Distance::add_dist(Distance d2, Distance d3)
   {
   inches = d2.inches + d3.inches;  //add the inches
   feet = 0;                      //(for possible carry)
   if(inches >= 12.0)             //if total exceeds 12.0,
      {                           //then decrease inches
      inches -= 12.0;             //by 12.0 and
      feet++;                     //increase feet
      }                           //by 1
   feet += d2.feet + d3.feet;     //add the feet
   }
//--------------------------------------------------------------
				  //divide Distance by int
void Distance::div_dist(Distance d2, int divisor)
   {
   float fltfeet = d2.feet + d2.inches/12.0;  //convert to float
   fltfeet /= divisor;                        //do division
   feet = int(fltfeet);                       //get feet part
   inches = (fltfeet-feet) * 12.0;            //get inches part
   }
////////////////////////////////////////////////////////////////
int main()
    {
   Distance distarr[100];         //array of 100 Distances
   Distance total(0, 0.0), average;  //other Distances
   int count = 0;                 //counts Distances input
   char ch;                       //user response character
   
   do {
      cout << "\nEnter a Distance";           //get Distances
      distarr[count++].getdist();             //from user, put
      cout << "\nDo another (y/n)? ";         //in array
      cin >> ch;
      }while( ch != 'n' );
   
   for(int j=0; j<count; j++)                 //add all Distances
      total.add_dist( total, distarr[j] );    //to total
   average.div_dist( total, count );          //divide by number

   cout << "\nThe average is: ";              //display average
   average.showdist();
   cout << endl;
   return 0;
   }
