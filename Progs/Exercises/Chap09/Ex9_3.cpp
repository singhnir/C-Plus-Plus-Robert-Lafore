// ex9_3.cpp
// multiple inheritance with publication class
#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////
class publication
   {
   private:
      string title;
      float price;
   public:
      void getdata()
         {
         cout << "\nEnter title: "; cin >> title;
         cout << "   Enter price: "; cin >> price;
         }
      void putdata() const
         {
         cout << "\nTitle: " << title;
         cout << "\n   Price: " << price;
         }
   };
////////////////////////////////////////////////////////////////
class sales
   {
   private:
      enum { MONTHS = 3 };
      float salesArr[MONTHS];
   public:
      void getdata();
      void putdata() const;
   };
//--------------------------------------------------------------
void sales::getdata()
   {
   cout << "   Enter sales for 3 months\n";
   for(int j=0; j<MONTHS; j++)
      {
      cout << "      Month " << j+1 << ": ";
      cin >> salesArr[j];
      }
   }
//--------------------------------------------------------------
void sales::putdata() const
   {
   for(int j=0; j<MONTHS; j++)
      {
      cout << "\n   Sales for month " << j+1 << ": ";
      cout << salesArr[j];
      }
   }
////////////////////////////////////////////////////////////////
class book : private publication, private sales
   {
   private:
      int pages;
   public:
      void getdata()
         {
         publication::getdata();
         cout << "   Enter number of pages: "; cin >> pages;
         sales::getdata();
         }
      void putdata() const
         {
         publication::putdata();
         cout << "\n   Pages: " << pages;
         sales::putdata();
         }
   };
////////////////////////////////////////////////////////////////
class tape : private publication, private sales
   {
   private:
      float time;
   public:
      void getdata()
         {
         publication::getdata();
         cout << "   Enter playing time: "; cin >> time;
         sales::getdata();
         }
      void putdata() const
         {
         publication::putdata();
         cout << "\n   Playing time: " << time;
         sales::putdata();
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   book book1;        // define publications
   tape tape1;

   book1.getdata();   // get data for publications
   tape1.getdata();

   book1.putdata();   // display data for publications
   tape1.putdata();
   cout << endl;
   return 0;
   }