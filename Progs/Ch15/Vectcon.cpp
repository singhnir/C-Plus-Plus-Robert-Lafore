// vectcon.cpp
// demonstrates constructors, swap(), empty(), back(), pop_back()
#include <iostream>
#include <vector>
using namespace std;

int main()
	{                              // an array of doubles
	double arr[] = { 1.1, 2.2, 3.3, 4.4 };

	vector<double> v1(arr, arr+4); // initialize vector to array
	vector<double> v2(4);          // empty vector of size 4

   v1.swap(v2);                   // swap contents of v1 and v2

	while( !v2.empty() )           // until vector is empty,
		{
		cout << v2.back() << ' ';   // display the last element
      v2.pop_back();              // remove the last element
      }                           // output: 4.4 3.3 2.2 1.1
   cout << endl;
   return 0;
	}

