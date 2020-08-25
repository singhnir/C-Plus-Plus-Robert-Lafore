// verylong.cpp
// implements very long integer type
#include "verylong.h"          //header file for verylong
//--------------------------------------------------------------
void verylong::putvl() const           //display verylong
   {
   char temp[SZ];
   strcpy(temp,vlstr);                 //make copy
   cout << strrev(temp);               //reverse the copy
   }                                   //and display it
//--------------------------------------------------------------
void verylong::getvl()                 //get verylong from user
   {
   cin >> vlstr;                       //get string from user
   vlen = strlen(vlstr);               //find its length
   strrev(vlstr);                      //reverse it
   }
//--------------------------------------------------------------
verylong verylong::operator + (const verylong v) //add verylongs
   {
   char temp[SZ];
   int j;
				       //find longest number
   int maxlen = (vlen > v.vlen) ? vlen : v.vlen;
   int carry = 0;                      //set to 1 if sum >= 10
   for(j = 0; j<maxlen; j++)           //for each position
      {
      int d1 = (j > vlen-1)   ? 0 : vlstr[j]-'0';   //get digit
      int d2 = (j > v.vlen-1) ? 0 : v.vlstr[j]-'0'; //get digit
      int digitsum = d1 + d2 + carry;               //add digits
      if( digitsum >= 10 )             //if there's a carry,
         { digitsum -= 10; carry=1; }  //decrease sum by 10,
      else                             //set carry to 1
         carry = 0;                    //otherwise carry is 0
      temp[j] = digitsum+'0';          //insert char in string
      }
   if(carry==1)                        //if carry at end,
      temp[j++] = '1';                 //last digit is 1
   temp[j] = '\0';                     //terminate string
   return verylong(temp);              //return temp verylong
   }
//--------------------------------------------------------------
verylong verylong::operator * (const verylong v)  //multiply 
   {                                              //verylongs
   verylong pprod;                     //product of one digit
   verylong tempsum;                   //running total
   for(int j=0; j<v.vlen; j++)         //for each digit in arg
      {
      int digit = v.vlstr[j]-'0';      //get the digit
      pprod = multdigit(digit);        //multiply this by digit
      for(int k=0; k<j; k++)           //multiply result by
         pprod = mult10(pprod);        //   power of 10
      tempsum = tempsum + pprod;       //add product to total
      }
   return tempsum;                     //return total of prods
   }
//--------------------------------------------------------------
verylong verylong::mult10(const verylong v) const //multiply
   {                                              //arg by 10
   char temp[SZ];
   for(int j=v.vlen-1; j>=0; j--)      //move digits one 
      temp[j+1] = v.vlstr[j];          //   position higher
   temp[0] = '0';                      //put zero on low end
   temp[v.vlen+1] = '\0';              //terminate string
   return verylong(temp);              //return result
   }
//--------------------------------------------------------------
verylong verylong::multdigit(const int d2) const 
   {                                   //multiply this verylong
   char temp[SZ];                      //by digit in argument
   int j, carry = 0;
   for(j = 0; j<vlen; j++)             //for each position
      {                                //   in this verylong
      int d1 = vlstr[j]-'0';           //get digit from this
      int digitprod = d1 * d2;         //multiply by that digit
      digitprod += carry;              //add old carry
      if( digitprod >= 10 )            //if there's a new carry,
         {
         carry = digitprod/10;         //carry is high digit
         digitprod -= carry*10;        //result is low digit
         }
      else
         carry = 0;                    //otherwise carry is 0
      temp[j] = digitprod+'0';         //insert char in string
      }
   if(carry != 0)                      //if carry at end,
      temp[j++] = carry+'0';           //it's last digit
   temp[j] = '\0';                     //terminate string
   return verylong(temp);              //return verylong
   }
