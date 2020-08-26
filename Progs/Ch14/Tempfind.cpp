// tempfind.cpp
// template used for function that finds number in array
#include <iostream>
using namespace std;
//--------------------------------------------------------------
// function returns index number of item, or -1 if not found
template <class atype>
int find(atype* array, atype value, int size)
	{
	for(int j=0; j<size; j++)
		if(array[j]==value)
			return j;
	return -1;
	}
//--------------------------------------------------------------
char chrArr[] =   {1, 3, 5, 9, 11, 13};  //array
char ch = 5;                             //value to find
int intArr[] =    {1, 3, 5, 9, 11, 13};
int in = 6;
long lonArr[] =   {1L, 3L, 5L, 9L, 11L, 13L};
long lo = 11L;
double dubArr[] = {1.0, 3.0, 5.0, 9.0, 11.0, 13.0};
double db = 4.0;

int main()
	{
	cout << "\n 5 in chrArray: index=" << find(chrArr, ch, 6);
	cout << "\n 6 in intArray: index=" << find(intArr, in, 6);
	cout << "\n11 in lonArray: index=" << find(lonArr, lo, 6);
	cout << "\n 4 in dubArray: index=" << find(dubArr, db, 6);
   cout << endl;
   return 0;
	}
