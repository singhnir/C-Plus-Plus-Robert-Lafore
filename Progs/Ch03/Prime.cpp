// prime.cpp
// demonstrates IF statement with prime numbers
#include <iostream>
using namespace std;
#include <process.h>             //for exit()

int main()
   {
   unsigned long n, j;           

   cout << "Enter a number: ";
   cin >> n;                     //get number to test
   for(j=2; j <= n/2; j++)       //divide by every integer from
      if(n%j == 0)               //2 on up; if remainder is 0,
         {                       //it's divisible by j
         cout << "It's not prime; divisible by " << j << endl;
         exit(0);                //exit from the program
         }
   cout << "It's prime\n";
   return 0;
   }