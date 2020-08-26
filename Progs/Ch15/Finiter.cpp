// finiter.cpp
// demonstrates istream_iterator with files
#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
   {
   list<int> iList;              // empty list
   ifstream infile("ITER.DAT");  // create input file object
                                 // (ITER.DAT must already exist)
                                 // istream iterators
   istream_iterator<int> file_iter(infile);  // file
   istream_iterator<int> end_of_stream;      // eos
                                 // copy from infile to iList
   copy( file_iter, end_of_stream, back_inserter(iList) );

   cout << endl;                 // display iList
   ostream_iterator<int> ositer(cout, "--");
   copy(iList.begin(), iList.end(), ositer);
   cout << endl;
   return 0;
   }
