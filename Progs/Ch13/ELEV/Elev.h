// elev.h
// header file for elevators -- contains class declarations

#include "elev_app.h"                //provided by client
#include "msoftcon.h"                //for console graphics
#include <iostream>
#include <iomanip>                   //for setw()
#include <conio.h>                   //for screen output
#include <stdlib.h>                  //for itoa()
#include <process.h>                 //for exit()
using namespace std;

enum direction { UP, DN, STOP };
const int LOAD_TIME =    3;   //loading/unloading time (ticks)
const int SPACING =      7;   //visual spacing between cars
const int BUF_LENGTH =  80;   //length of utility string buffer

class building;                   //forward declaration
////////////////////////////////////////////////////////////////
class elevator
   {
   private:
   building* ptrBuilding;         //ptr to parent building
   const int car_number;          //our number (0 to nc-1)
   int current_floor;             //where are we? (0 to nf-1)
   int old_floor;                 //where were we? (0 to nf-1)
   direction current_dir;         //which way are we going?
   bool destination[NUM_FLOORS];  //selected by occupants
   int loading_timer;             //non-zero if loading
   int unloading_timer;           //non-zero if unloading

   public:
   elevator(building*, int);      //constructor
   void car_tick1();              //time tick 1 for each car
   void car_tick2();              //time tick 2 for each car
   void car_display();            //display elevator
   void dests_display() const;    //display elevator requests
   void decide();                 //decide what to do
   void move();                   //move the car
   void get_destinations();       //get destinations
   int get_floor() const;         //get current floor
   direction get_direction() const;  //get current direction
   };
////////////////////////////////////////////////////////////////
class building
   {
   private:
   elevator* car_list[NUM_CARS];  //ptrs to cars
   int num_cars;                  //cars created so far
                                  //array of up/down buttons
   bool floor_request[2][NUM_FLOORS]; //false=UP, true=DN

   public:
   building();                    //constructor
   ~building();                   //destructor
   void master_tick();            //send ticks to all cars
   int get_cars_floor(const int) const; //find where a car is
                                  //find which way car is going
   direction get_cars_dir(const int) const;   
                                  //check specific floor req
   bool get_floor_req(const int, const int) const; 
                                  //set specific floor req
   void set_floor_req(const int, const int, const bool);  
   void record_floor_reqs();      //get floor requests
   void show_floor_reqs() const;  //show floor requests
   };
////////////////////////////////////////////////////////////////

