// ex15_2.cpp
// vector used with string objects, push_back(), and []
#include <iostream>
#include <string>
#pragma warning (disable:4786)  //Microsoft only
#include <vector>
#include <algorithm>
using namespace std;

int main()
   {
   vector<string> vectStrings;
   string word;
   char ch;

   do {
      cout << "Enter a word: ";
      cin >> word;
      vectStrings.push_back(word);
      cout << "Enter another ('y' or 'n'): ";
      cin >> ch;
      } while(ch == 'y');
   sort( vectStrings.begin(), vectStrings.end() );
   for(int k=0; k<vectStrings.size(); k++)
      cout << vectStrings[k] << endl;
   return 0;
   }