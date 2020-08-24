// horse.cpp
// models a horse race
#include "msoftcon.h"               //for console graphics
#include <iostream>                 //for I/O
#include <cstdlib>                  //for random()
#include <ctime>                    //for time()
using namespace std;
const int CPF = 5;                  //columns per furlong
const int maxHorses = 7;            //maximum number of horses
class track;                        //for forward references
////////////////////////////////////////////////////////////////
class horse
   {
   private:
      const track* ptrTrack;        //pointer to track
      const int horse_number;       //this horse's number
      float finish_time;            //this horse's finish time
      float distance_run;           //distance run so far
   public:                          //create the horse
      horse(const int n, const track* ptrT) : 
               horse_number(n), ptrTrack(ptrT), 
               distance_run(0.0)    //haven't moved yet
          {  }   
      ~horse()                      //destroy the horse
         { /*empty*/ }              //display the horse
      void display_horse(const float elapsed_time);
   };  //end class horse
////////////////////////////////////////////////////////////////
class track
   {
   private:
      horse* hArray[maxHorses];     //array of ptrs-to-horses
      int total_horses;             //total number of horses
      int horse_count;              //horses created so far
      const float track_length;     //track length in furlongs
      float elapsed_time;           //time since start of race

   public:
      track(float lenT, int nH);    //2-arg constructor
      ~track();                     //destructor
      void display_track();         //display track
      void run();                   //run the race
      float get_track_len() const;  //return total track length
   };  //end class track
//---------------------------------------------------------------
void horse::display_horse(float elapsed_time) //for each horse
   {                                //display horse & number
   set_cursor_pos( 1 + int(distance_run * CPF),
           2 + horse_number*2 );
                                    //horse 0 is blue
   set_color(static_cast<color>(cBLUE+horse_number));
                                    //draw horse
   char horse_char = '0' + static_cast<char>(horse_number);
   putch(' '); putch('\xDB'); putch(horse_char); putch('\xDB');
                                    //until finish,
   if( distance_run < ptrTrack->get_track_len() + 1.0 / CPF )
      {
      if( rand() % 3 )              //skip about 1 of 3 ticks
         distance_run += 0.2F;      //advance 0.2 furlongs
      finish_time = elapsed_time;   //update finish time
      }
   else
      {                             //display finish time
      int mins = int(finish_time)/60;
      int secs = int(finish_time) - mins*60;
      cout << " Time=" << mins << ":" << secs;
      }
   }  //end display_horse()
//---------------------------------------------------------------
track::track(float lenT, int nH) :  //track constructor
                     track_length(lenT), total_horses(nH),
                     horse_count(0), elapsed_time(0.0)
         {
         init_graphics();           //start graphics                                      
         total_horses =             //not more than 7 horses
          (total_horses > maxHorses) ? maxHorses : total_horses; 
         for(int j=0; j<total_horses; j++)   //make each horse
            hArray[j] = new horse(horse_count++, this);

         time_t aTime;              //initialize random numbers
         srand( static_cast<unsigned>(time(&aTime)) );
         display_track();
         }  //end track constructor
//---------------------------------------------------------------
track::~track()                     //track destructor
   {
   for(int j=0; j<total_horses; j++) //delete each horse
      delete hArray[j];
   }
//---------------------------------------------------------------
void track::display_track()
   {
   clear_screen();                  //clear screen
                                    //display track
   for(int f=0; f<=track_length; f++)    //for each furlong
      for(int r=1; r<=total_horses*2 + 1; r++) //and screen row
         {
         set_cursor_pos(f*CPF + 5, r);
         if(f==0 || f==track_length)
            cout << '\xDE';         //draw start or finish line
         else
            cout << '\xB3';         //draw furlong marker
         }
   }  //end display_track()
//---------------------------------------------------------------
void track::run()
   {
   while( !kbhit() )
      {
      elapsed_time += 1.75;         //update time
                                    //update each horse
      for(int j=0; j<total_horses; j++)  
         hArray[j]->display_horse(elapsed_time);
      wait(500);
      }
   getch();                         //eat the keystroke
   cout << endl;                         
   }
//---------------------------------------------------------------
float track::get_track_len() const
   { return track_length; }
/////////////////////////////////////////////////////////////////
int main()
   {
   float length;
   int total;
                                    //get data from user
   cout << "\nEnter track length (furlongs; 1 to 12): ";
   cin >> length;
   cout << "\nEnter number of horses (1 to 7): ";
   cin >> total;                             
   track theTrack(length, total);   //create the track
   theTrack.run();                  //run the race
   return 0;
   }  //end main()

