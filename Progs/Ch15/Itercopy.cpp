// itercopy.cpp
// uses iterators for copy() algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
   {
   int beginRange, endRange;
   int arr[] = { 11, 13, 15, 17, 19, 21, 23, 25, 27, 29 };
   vector<int> v1(arr, arr+10);  // initialized vector
   vector<int> v2(10);           // uninitialized vector

   cout << "Enter range to be copied (example: 2 5): ";
   cin >> beginRange >> endRange;

   vector<int>::iterator iter1 = v1.begin() + beginRange;
   vector<int>::iterator iter2 = v1.begin() + endRange;
   vector<int>::iterator iter3;
                                 // copy range from v1 to v2
   iter3 = copy( iter1, iter2, v2.begin() );
                                 // (it3 -> last item copied)
   iter1 = v2.begin();           // iterate through range
   while(iter1 != iter3)         // in v2, displaying values
      cout << *iter1++ << ' ';
   cout << endl;
   return 0;
   }
