// sortemp.cpp
// sorts array of doubles in backwards order,
// uses greater<>() function object
#include <iostream>
#include <algorithm>                  //for sort()
#include <functional>                 //for greater<>
using namespace std;
                                      // array of doubles
double fdata[] = { 19.2, 87.4, 33.6, 55.0, 11.5, 42.2 };

int main()
   {                                  // sort the doubles
   sort( fdata, fdata+6, greater<double>() );

   for(int j=0; j<6; j++)             // display sorted doubles
      cout << fdata[j] << ' ';
   cout << endl;
   return 0;
   }

