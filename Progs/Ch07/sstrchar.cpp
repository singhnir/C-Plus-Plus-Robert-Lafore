//sstrchar.cpp
//accessing characters in string objects
#include <iostream>
#include <string>
using namespace std;

int main()
   {
   char charray[80];
   string word; 
   
   cout << "Enter a word: ";
   cin >> word;
   int wlen = word.length();     //length of string object

   cout << "One character at a time: ";
   for(int j=0; j<wlen; j++)
      cout << word.at(j);        //exception if out-of-bounds
//    cout << word[j];           //no warning if out-of-bounds

   word.copy(charray, wlen, 0);  //copy string object to array
   charray[wlen] = 0;            //terminate with '\0'
   cout << "\nArray contains: " << charray << endl;
   return 0;
   }