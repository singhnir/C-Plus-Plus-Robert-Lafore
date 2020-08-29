// ex11_3.cpp
// creates array class
// overloads assignment operator and copy constructor
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Array
   {
   private:
      int* ptr;                 //pointer to "array" contents
      int size;                 //size of array
   public:
      Array() : ptr(0), size(0) //no-argument constructor
         { }
      Array(int s) : size(s)    //one-argument constructor
         { ptr = new int[s]; }
      Array(Array&);            //copy constructor
      ~Array()                  //destructor
         { delete[] ptr; }
      int& operator [] (int j)  //overloaded subscript op
         { return *(ptr+j); }
      Array& operator = (Array&);  //overloaded = operator
   };
//--------------------------------------------------------------
Array::Array(Array& a)          //copy constructor
   {
   size = a.size;               //new one is same size
   ptr = new int[size];         //get space for contents
   for(int j=0; j<size; j++)    //copy contents to new one
      *(ptr+j) = *(a.ptr+j);
   }
//--------------------------------------------------------------
Array& Array::operator = (Array& a)  //overloaded = operator
   {
   delete[] ptr;                //delete old contents (if any)
   size = a.size;               //make this object same size
   ptr = new int[a.size];       //get space for new contents       
   for(int j=0; j<a.size; j++)  //copy contents to this object
      *(ptr+j) = *(a.ptr+j);
   return *this;                //return this object
   }
////////////////////////////////////////////////////////////////
int main()
   {
   const int ASIZE = 10;        //size of array
   Array arr1(ASIZE);           //make an array

   for(int j=0; j<ASIZE; j++)   //fill it with squares
      arr1[j] = j*j;

   Array arr2(arr1);            //use the copy constructor
   cout << "\narr2: ";
   for(j=0; j<ASIZE; j++)       //check that it worked
      cout << arr2[j] << "  ";

   Array arr3, arr4;            //make two empty Array objects
   arr4 = arr3 = arr1;          //use the assignment operator
   cout << "\narr3: ";
   for(j=0; j<ASIZE; j++)       //check that it worked on arr3
      cout << arr3[j] << "  ";
   cout << "\narr4: ";
   for(j=0; j<ASIZE; j++)       //check that it worked on arr4
      cout << arr4[j] << "  ";
   cout << endl;
   return 0;
   }
