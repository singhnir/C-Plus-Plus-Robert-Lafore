// showprim.cpp
// displays prime number distribution
#include <iostream>
using namespace std;
#include <conio.h>               //for getche()

int main()
   {
   const unsigned char WHITE = 219;  //solid color (primes)
   const unsigned char GRAY  = 176;  //gray (non primes)
   unsigned char ch;
                                 //for each screen position
   for(int count=0; count<80*25-1; count++)
      {
      ch = WHITE;                //assume it's prime
      for(int j=2; j<count; j++) //divide by every integer from
         if(count%j == 0)        //2 on up; if remainder is 0,
            {
            ch = GRAY;           //it's not prime
            break;               //break out of inner loop
            }
      cout << ch;                //display the character
      }
   getche();                     //freeze screen until keypress
   return 0;
   }