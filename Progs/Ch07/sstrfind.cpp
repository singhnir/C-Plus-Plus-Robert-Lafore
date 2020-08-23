//sstrfind.cpp
//finding substrings in string objects
#include <iostream>
#include <string>
using namespace std;

int main()
   {
   string s1 =
      "In Xanadu did Kubla Kahn a stately pleasure dome decree";
   int n;

   n = s1.find("Kubla");
   cout << "Found Kubla at " << n << endl;

   n = s1.find_first_of("spde");
   cout << "First of spde at " << n << endl;

   n = s1.find_first_not_of("aeiouAEIOU");
   cout << "First consonent at " << n << endl;
   return 0;
   }