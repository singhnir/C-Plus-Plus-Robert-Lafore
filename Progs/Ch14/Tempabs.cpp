// tempabs.cpp
// template used for absolute value function
#include <iostream>
using namespace std;
//--------------------------------------------------------------
template <class T>             //function template
T abs(T n)
	{
	return (n < 0) ? -n : n;
	}
//--------------------------------------------------------------
int main()
	{
	int int1 = 5;
	int int2 = -6;
	long lon1 = 70000L;
	long lon2 = -80000L;
	double dub1 = 9.95;
	double dub2 = -10.15;
                               //calls instantiate functions
	cout << "\nabs(" << int1 << ")=" << abs(int1);  //abs(int)
	cout << "\nabs(" << int2 << ")=" << abs(int2);  //abs(int)
	cout << "\nabs(" << lon1 << ")=" << abs(lon1);  //abs(long)
	cout << "\nabs(" << lon2 << ")=" << abs(lon2);  //abs(long)
	cout << "\nabs(" << dub1 << ")=" << abs(dub1);  //abs(double)
	cout << "\nabs(" << dub2 << ")=" << abs(dub2);  //abs(double)
   cout << endl;
   return 0;
	}
