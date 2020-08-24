// englmult.cpp
// multiple inheritance with English Distances
#include <iostream>
#include <string>                
using namespace std;
////////////////////////////////////////////////////////////////
class Type                        //type of lumber
   {
   private:
      string dimensions;
      string grade;
   public:                        //no-arg constructor
      Type() : dimensions("N/A"), grade("N/A")
         {  }
                                  //2-arg constructor
      Type(string di, string gr) : dimensions(di), grade(gr) 
         {  }
      void gettype()              //get type from user
         {
         cout << "   Enter nominal dimensions (2x4 etc.): ";
         cin >> dimensions;
         cout << "   Enter grade (rough, const, etc.): ";
         cin >> grade;
         }
      void showtype() const       //display type
         {
         cout << "\n   Dimensions: " << dimensions;
         cout << "\n   Grade: " << grade;
         }
   };
////////////////////////////////////////////////////////////////
class Distance                    //English Distance class
   {
   private:
      int feet;
      float inches;
   public:                        //no-arg constructor
      Distance() : feet(0), inches(0.0)
         {  }                     //constructor (two args)
      Distance(int ft, float in) : feet(ft), inches(in)  
         {  }
      void getdist()              //get length from user
         {
         cout << "   Enter feet: ";  cin >> feet;
         cout << "   Enter inches: ";  cin >> inches;
         }
      void showdist() const       //display distance
         { cout  << feet << "\'-" << inches << '\"'; }
   };
////////////////////////////////////////////////////////////////
class Lumber : public Type, public Distance
   {
   private:
      int quantity;                      //number of pieces
      double price;                      //price of each piece
   public:                               //constructor (no args)
      Lumber() : Type(), Distance(), quantity(0), price(0.0)      
         {  }
					 //constructor (6 args)
      Lumber( string di, string gr,      //args for Type
              int ft, float in,          //args for Distance
              int qu, float prc ) :      //args for our data
              Type(di, gr),              //call Type ctor
              Distance(ft, in),          //call Distance ctor
              quantity(qu), price(prc)   //initialize our data
          {  }
      void getlumber()
         {
         Type::gettype();
         Distance::getdist();
         cout << "   Enter quantity: "; cin >> quantity;
         cout << "   Enter price per piece: "; cin >> price;
         }
      void showlumber() const
         {
         Type::showtype();
         cout << "\n   Length: ";
         Distance::showdist();
         cout << "\n   Price for " << quantity
	         << " pieces: $" << price * quantity;
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   Lumber siding;                   //constructor (no args)

   cout << "\nSiding data:\n";
   siding.getlumber();              //get siding from user

                                    //constructor (6 args)
   Lumber studs( "2x4", "const", 8, 0.0, 200, 4.45F );

                                    //display lumber data
   cout << "\nSiding";  siding.showlumber();
   cout << "\nStuds";     studs.showlumber();
   cout << endl;
   return 0;
   }
