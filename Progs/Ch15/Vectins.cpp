// vectins.cpp
// demonstrates insert(), erase()
#include <iostream>
#include <vector>
using namespace std;

int main()
	{
	int arr[] = { 100, 110, 120, 130 };  //an array of ints

	vector<int> v(arr, arr+4);       // initialize vector to array

   cout << "\nBefore insertion: ";
   for(int j=0; j<v.size(); j++)    // display all elements
		cout << v[j] << ' ';

   v.insert( v.begin()+2, 115);     // insert 115 at element 2

   cout << "\nAfter insertion:  ";
   for(j=0; j<v.size(); j++)        // display all elements
		cout << v[j] << ' ';

   v.erase( v.begin()+2 );          // erase element 2

   cout << "\nAfter erasure:    ";
   for(j=0; j<v.size(); j++)        // display all elements
		cout << v[j] << ' ';
   cout << endl;
   return 0;
	}

