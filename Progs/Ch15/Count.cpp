// count.cpp
// counts the number of objects with a specified value
#include <iostream>
#include <algorithm>               //for count()
using namespace std;

int arr[] = { 33, 22, 33, 44, 33, 55, 66, 77 };

int main()
   {
   int n = count(arr, arr+8, 33);  //count number of 33's                                  
   cout << "There are " << n << " 33's in arr." << endl;
   return 0;
   }
