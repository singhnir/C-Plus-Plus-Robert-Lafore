// wdcount.cpp
// demonstrates enums, counts words in phrase
#include <iostream>
using namespace std;
#include <conio.h>             //for getche()

enum itsaWord { NO, YES };     //NO=0, YES=1

int main()
   {
   itsaWord isWord = NO;       //YES when in a word,
                               //NO when in whitespace
   char ch = 'a';              //character read from keyboard
   int wordcount = 0;          //number of words read

   cout << "Enter a phrase:\n";
   do {
      ch = getche();           //get character
      if(ch==' ' || ch=='\r')  //if white space,
         {
         if( isWord == YES )   //and doing a word,
            {                  //then it's end of word
            wordcount++;       //count the word
            isWord = NO;       //reset flag
            }
         }                     //otherwise, it's
      else                     //normal character
         if( isWord == NO )    //if start of word,
            isWord = YES;      //then set flag
      } while( ch != '\r' );   //quit on Enter key
   cout << "\n---Word count is " << wordcount << "---\n";
   return 0;
   }
