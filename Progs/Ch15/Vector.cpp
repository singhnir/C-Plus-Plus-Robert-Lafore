// vector.cpp
// demonstrates push_back(), operator[], size()
#include <iostream>
#include <vector>
using namespace std;

int main()
	{
	vector<int> v;                 // create a vector of ints

	v.push_back(10);               // put values at end of array
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);

	v[0] = 20;                     // replace with new values
	v[3] = 23;
   
	for(int j=0; j<v.size(); j++)  // display vector contents
		cout << v[j] << ' ';        // 20 11 12 23
   cout << endl;
   return 0;
	}

