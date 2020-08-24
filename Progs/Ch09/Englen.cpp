// englen.cpp
// inheritance using English Distances
#include <iostream>
using namespace std;
enum posneg { pos, neg };         //for sign in DistSign
////////////////////////////////////////////////////////////////
class Distance                    //English Distance class
   {
   protected:                     //NOTE: can't be private
      int feet;
      float inches;
   public:                        //no-arg constructor
      Distance() : feet(0), inches(0.0)
         {  }                     //2-arg constructor)
      Distance(int ft, float in) : feet(ft), inches(in)  
         {  }
      void getdist()              //get length from user
         {
         cout << "\nEnter feet: ";  cin >> feet;
         cout << "Enter inches: ";  cin >> inches;
         }
      void showdist() const       //display distance
         { cout << feet << "\'-" << inches << '\"'; }
   };
////////////////////////////////////////////////////////////////
class DistSign : public Distance  //adds sign to Distance
   {
   private:
      posneg sign;                //sign is pos or neg
   public:
                                  //no-arg constructor
      DistSign() : Distance()     //call base constructor
         { sign = pos; }          //set the sign to +

                                  //2- or 3-arg constructor
      DistSign(int ft, float in, posneg sg=pos) :
              Distance(ft, in)    //call base constructor
         { sign = sg; }           //set the sign

      void getdist()              //get length from user
	       {
	       Distance::getdist();     //call base getdist()
	       char ch;                 //get sign from user
	       cout << "Enter sign (+ or -): ";  cin >> ch;
	       sign = (ch=='+') ? pos : neg;
	       }
      void showdist() const        //display distance
	       {
	       cout << ( (sign==pos) ? "(+)" : "(-)" );  //show sign
	       Distance::showdist();                     //ft and in
	       }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   DistSign alpha;                  //no-arg constructor
   alpha.getdist();                 //get alpha from user

   DistSign beta(11, 6.25);         //2-arg constructor

   DistSign gamma(100, 5.5, neg);   //3-arg constructor

				     //display all distances
   cout << "\nalpha = ";  alpha.showdist();
   cout << "\nbeta = ";  beta.showdist();
   cout << "\ngamma = ";  gamma.showdist();
   cout << endl;
   return 0;
   }
