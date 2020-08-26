// asso_arr.cpp
// demonstrates map used as associative array
#pragma warning (disable:4786)  //for map (Microsoft only)
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
   {
   string name;
   int pop;

   string states[] = { "Wyoming", "Colorado", "Nevada",
                       "Montana", "Arizona", "Idaho"};
   int pops[] = { 470, 2890, 800, 787, 2718, 944 };

   map<string, int, less<string> > mapStates;       //map
   map<string, int, less<string> >::iterator iter;  //iterator

   for(int j=0; j<6; j++)
      {
      name = states[j];                 //get data from arrays
      pop = pops[j];
      mapStates[name] = pop;            //put it in map
      }
   cout << "Enter state: ";             //get state from user               
   cin >> name;
   pop = mapStates[name];               //find population
   cout << "Population: " << pop << ",000\n";

   cout << endl;                        //display entire map
   for(iter = mapStates.begin(); iter != mapStates.end(); iter++)
      cout << (*iter).first << ' ' << (*iter).second << ",000\n";
   return 0;
   }