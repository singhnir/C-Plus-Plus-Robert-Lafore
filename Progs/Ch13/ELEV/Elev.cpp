// elev.cpp
// contains class data and member function definitions

#include "elev.h"     //include class declarations
////////////////////////////////////////////////////////////////
//           function definitions for class building      
////////////////////////////////////////////////////////////////
building::building()                 //constructor
   {
   char ustring[BUF_LENGTH];         //string for floor numbers

   init_graphics();                  //initialize graphics
   clear_screen();                   //clear screen
   num_cars = 0;
   for(int k=0; k<NUM_CARS; k++)     //make elevators
      {
      car_list[k] = new elevator(this, num_cars);
      num_cars++;                       
      }
   for(int j=0; j<NUM_FLOORS; j++)   //for each floor
      {
      set_cursor_pos(3, NUM_FLOORS-j);  //put floor number
      itoa(j+1, ustring, 10);           //on screen
      cout << setw(3) << ustring;
      floor_request[UP][j] = false;  //no floor requests yet
      floor_request[DN][j] = false;
      }
   }  //end constructor
//--------------------------------------------------------------
building::~building()                //destructor
   {
   for(int k=0; k<NUM_CARS; k++)     //destroy elevators
      delete car_list[k];
   }
//--------------------------------------------------------------
void building::master_tick()         //master time tick
   {
   int j;
   show_floor_reqs();                //display floor requests
   for(j=0; j<NUM_CARS; j++)         //for each elevator
      car_list[j]->car_tick1();      //send it time tick 1
   for(j=0; j<NUM_CARS; j++)         //for each elevator
      car_list[j]->car_tick2();      //send it time tick 2
   }  //end master_tick()
//--------------------------------------------------------------
void building::show_floor_reqs() const  //display floor requests
   {
   for(int j=0; j<NUM_FLOORS; j++)
      {
      set_cursor_pos(SPACING, NUM_FLOORS-j);
      if(floor_request[UP][j]==true)
         cout << '\x1E';             //up arrow
      else
         cout << ' ';
      set_cursor_pos(SPACING+3, NUM_FLOORS-j);
      if(floor_request[DN][j]==true)
         cout << '\x1F';             //down arrow
      else
         cout << ' ';
      }
   }  //end show_floor_reqs()
//--------------------------------------------------------------
//record_floor_reqs() -- get requests from riders outside car
void building::record_floor_reqs()
   {
   char ch = 'x';             //utility char for input
   char ustring[BUF_LENGTH];  //utility string for input
   int iFloor;                //floor from which request made
   char chDirection;          //'u' or 'd' for up or down
   
   set_cursor_pos(1,22);      //bottom of screen
   cout << "Press [Enter] to call an elevator: ";
   if( !kbhit() )             //wait for keypress (must be CR)
      return;
   cin.ignore(10, '\n');
   if(ch=='\x1B')             //if escape key, end program
      exit(0);
   set_cursor_pos(1,22); clear_line();  //clear old text
   set_cursor_pos(1,22);      //bottom of screen
   cout << "Enter the floor you're on: ";
   cin.get(ustring, BUF_LENGTH);        //get floor
   cin.ignore(10, '\n');      //eat chars, including newline
   iFloor = atoi(ustring);    //convert to integer

   cout << "Enter direction you want to go (u or d): ";
   cin.get(chDirection);      //(avoid multiple linefeeds)
   cin.ignore(10, '\n');      //eat chars, including newline

   if(chDirection=='u' || chDirection=='U')
      floor_request[UP][iFloor-1] = true;  //up floor request
   if(chDirection=='d' || chDirection=='D')
      floor_request[DN][iFloor-1] = true;  //down floor request
   set_cursor_pos(1,22); clear_line();     //clear old text
   set_cursor_pos(1,23); clear_line();
   set_cursor_pos(1,24); clear_line();
   }  //end record_floor_reqs()
//--------------------------------------------------------------
//get_floor_req() -- see if there's a specific request
bool building::get_floor_req(const int dir,
                             const int floor) const
   {
   return floor_request[dir][floor];
   }
//--------------------------------------------------------------
//set_floor_req() -- set specific floor request
void building::set_floor_req(const int dir, const int floor,
                             const bool updown)
   {
   floor_request[dir][floor] = updown;
   }
//--------------------------------------------------------------
//get_cars_floor() -- find where a car is
int building::get_cars_floor(const int carNo) const
   {
   return car_list[carNo]->get_floor();
   }
//--------------------------------------------------------------
//get_cars_dir() -- find which way car is going
direction building::get_cars_dir(const int carNo) const
   {
   return car_list[carNo]->get_direction();
   }
//--------------------------------------------------------------

/////////////////////////////////////////////////////////////////
//           function definitions for class elevator
/////////////////////////////////////////////////////////////////
                                     //constructor
elevator::elevator(building* ptrB, int nc) : 
                               ptrBuilding(ptrB), car_number(nc)
   {
   current_floor = 0;                //start at 0 (user's 1)
   old_floor = 0;                    //remember previous floor
   current_dir = STOP;               //stationary at start
   for(int j=0; j<NUM_FLOORS; j++)   //occupants have not pushed
      destination[j] = false;        //   any buttons yet
   loading_timer = 0;                //not loading yet
   unloading_timer = 0;              //not unloading yet
                                  }  //end constructor
//--------------------------------------------------------------
int elevator::get_floor() const      //get current floor
   {
   return current_floor;
   }
//--------------------------------------------------------------
direction elevator::get_direction() const  //get current
   {                                       //  direction
   return current_dir;
   }
//--------------------------------------------------------------
void elevator::car_tick1()           //tick 1 for each car
   {
   car_display();                    //display elevator box
   dests_display();                  //display destinations
   if(loading_timer)                 //count down load time
      --loading_timer;
   if(unloading_timer)               //count down unload time
      --unloading_timer;
   decide();                         //decide what to do
   }  //end car_tick()
//--------------------------------------------------------------
//all cars must decide before any of them move
void elevator::car_tick2()           //tick 2 for each car
   {
   move();                           //move car if appropriate
   }
//--------------------------------------------------------------
void elevator::car_display()         //display elevator image
   {
   set_cursor_pos(SPACING+(car_number+1)*SPACING, NUM_FLOORS-old_floor);
   cout << "   ";                    //erase old position
   set_cursor_pos(SPACING-1+(car_number+1)*SPACING,
                                      NUM_FLOORS-current_floor);
   switch(loading_timer)
      {
      case 3:
         cout << "\x01\xDB \xDB ";   //draw car with open door
         break;                      //happy face on left
      case 2:
         cout << " \xDB\x01\xDB ";   //happy face in open door
         get_destinations();         //get destinations
         break;
      case 1:
         cout << " \xDB\xDB\xDB ";   //draw with closed door
         break;                      //no happy face
      case 0:
         cout << " \xDB\xDB\xDB ";   //closed door, no
         break;                      //happy face (default)
      }
   set_cursor_pos(SPACING+(car_number+1)*SPACING,
                                    NUM_FLOORS-current_floor);
   switch(unloading_timer)
      {
      case 3:
         cout << "\xDB\x01\xDB ";    //draw car with open door
         break;                      //happy face in car
      case 2:
         cout << "\xDB \xDB\x01";    //draw car with open door
         break;                      //happy face on right
      case 1:
         cout << "\xDB\xDB\xDB ";    //draw with closed door
         break;                      //no happy face
      case 0:
         cout << "\xDB\xDB\xDB ";    //closed door, no
         break;                      //happy face (default)
      }
   old_floor = current_floor;        //remember old floor
   }  //end car_display()
//--------------------------------------------------------------
void elevator::dests_display() const //display destinations
   {                                 //   selected by buttons
   for(int j=0; j<NUM_FLOORS; j++)   //   inside the car
      {
      set_cursor_pos(SPACING-2+(car_number+1)*SPACING, NUM_FLOORS-j);
      if( destination[j] == true )
         cout << '\xFE';             //small box
      else
         cout << ' ';                //blank
      }
   }  //end dests_display()
//--------------------------------------------------------------
void elevator::decide()               //decide what to do
   {
   int j;
   //flags indicate if destinations or requests above/below us
   bool destins_above, destins_below;    //destinations
   bool requests_above, requests_below;  //requests
   //floor number of closest request above us and below us
   int nearest_higher_req = 0;
   int nearest_lower_req = 0;
   //flags indicate if there is another car, going in the same
   //direction, between us and the nearest floor request (FR)
   bool car_between_up, car_between_dn;
   //flags indicate if there is another car, going in the
   //opposite direction, on the opposite side of the nearest FR
   bool car_opposite_up, car_opposite_dn;
   //floor and direction of other car (not us)
   int ofloor;                          //floor
   direction odir;                      //direction

   //ensure we don't go too high or too low
   if( (current_floor==NUM_FLOORS-1 && current_dir==UP)
      || (current_floor==0 && current_dir==DN) )
      current_dir = STOP;

   //if there's a destination on this floor, unload passengers
   if( destination[current_floor]==true )
      {
      destination[current_floor] = false;  //erase destination
      if( !unloading_timer)                //unload
         unloading_timer = LOAD_TIME;
      return;
      }
   //if there's an UP floor request on this floor,
   //and if we're going up or stopped, load passengers
   if( (ptrBuilding->get_floor_req(UP, current_floor) && 
        current_dir != DN) )
      {
      current_dir = UP;  //(in case it was STOP)
      //remove floor request for direction we're going
      ptrBuilding->set_floor_req(current_dir, 
                                 current_floor, false);
      if( !loading_timer)                  //load
         loading_timer = LOAD_TIME;
      return;
      }
   //if there's a down floor request on this floor,
   //and if we're going down or stopped, load passengers
   if( (ptrBuilding->get_floor_req(DN, current_floor) && 
        current_dir != UP) )
      {
      current_dir = DN;  //(in case it was STOP)
      //remove floor request for direction we're going
      ptrBuilding->set_floor_req(current_dir,
                                  current_floor, false);
      if( !loading_timer)                  //load passengers
         loading_timer = LOAD_TIME;
      return;
      }
   //check if there are other destinations or requests
   //record distance to nearest request
   destins_above = destins_below = false;
   requests_above = requests_below = false;
   for(j=current_floor+1; j<NUM_FLOORS; j++)
      {                                   //check floors above
      if( destination[j] )                //if destinations
         destins_above = true;            //set flag
      if( ptrBuilding->get_floor_req(UP, j) || 
          ptrBuilding->get_floor_req(DN, j) )
         {                                //if requests
         requests_above = true;           //set flag
         if( !nearest_higher_req )        //if not set before
            nearest_higher_req = j;       //   set nearest req
         }
      }
   for(j=current_floor-1; j>=0; j--)      //check floors below
      {
      if(destination[j] )                 //if destinations
         destins_below = true;            //set flag
      if( ptrBuilding->get_floor_req(UP, j) || 
          ptrBuilding->get_floor_req(DN, j) )
         {                                //if requests
         requests_below = true;           //set flag
         if( !nearest_lower_req )         //if not set before
            nearest_lower_req = j;        //   set nearest req
         }
      }
   //if no requests or destinations above or below, stop
   if( !destins_above && !requests_above &&
       !destins_below && !requests_below)
       {
       current_dir = STOP;
       return;
       }
   //if destinations and we're stopped, or already going the
   //right way, go toward destinations
   if( destins_above && (current_dir==STOP || current_dir==UP) )
      {
      current_dir = UP;
      return;
      }
   if( destins_below && (current_dir==STOP || current_dir==DN) )
      {
      current_dir = DN;
      return;
      }
   //find out if there are other cars, (a) going in the same
   //direction, between us and the nearest floor request;
   //or (b) going in the opposite direction, on the other
   //side of the floor request
   car_between_up = car_between_dn = false;
   car_opposite_up = car_opposite_dn = false;

   for(j=0; j<NUM_CARS; j++)              //check each car
      {
      if(j != car_number)                 //if it's not us
         {                                //get its floor
         ofloor = ptrBuilding->get_cars_floor(j);   //and
         odir = ptrBuilding->get_cars_dir(j); //direction

         //if it's going up and there are requests above us
         if( (odir==UP || odir==STOP) && requests_above )
            //if it's above us and below the nearest request
            if( (ofloor > current_floor
                && ofloor <= nearest_higher_req)
            //or on same floor as us but is lower car number
              || (ofloor==current_floor && j < car_number) )
               car_between_up = true;
         //if it's going down and there are requests below us
         if( (odir==DN || odir==STOP) && requests_below )
            //if it's below us and above the nearest request
            if( (ofloor < current_floor
                && ofloor >= nearest_lower_req)
               //or on same floor as us but is lower car number
               || (ofloor==current_floor && j < car_number) )
               car_between_dn = true;
         //if it's going up and there are requests below us
         if( (odir==UP || odir==STOP) && requests_below )
            //it's below request and closer to it than we are
            if(nearest_lower_req >= ofloor
               && nearest_lower_req - ofloor
                  < current_floor - nearest_lower_req)
               car_opposite_up = true;
         //if it's going down and there are requests above us
         if( (odir==DN || odir==STOP) && requests_above )
            //it's above request and closer to it than we are
            if(ofloor >= nearest_higher_req
               && ofloor - nearest_higher_req
                  < nearest_higher_req - current_floor)
               car_opposite_dn = true;
         }  //end if(not us)
      }  //end for(each car)

   //if we're going up or stopped, and there is an FR above us,
   //and there are no other cars going up between us and the FR,
   //or above the FR going down and closer than we are,
   //then go up
   if( (current_dir==UP || current_dir==STOP)
       && requests_above && !car_between_up && !car_opposite_dn )
      {
      current_dir = UP;
      return;
      }

   //if we're going down or stopped, and there is an FR below
   //us, and there are no other cars going down between us and
   //the FR, or below the FR going up and closer than we are,
   //then go down
   if( (current_dir==DN || current_dir==STOP)
       && requests_below && !car_between_dn && !car_opposite_up )
      {
      current_dir = DN;
      return;
      }
   //if nothing else happening, stop
   current_dir = STOP;
   }  //end decide(), finally
//--------------------------------------------------------------
void elevator::move() 
   {                          //if loading or unloading,
   if(loading_timer || unloading_timer)  //don't move
      return;
   if(current_dir==UP)        //if going up, go up
      current_floor++;
   else if(current_dir==DN)   //if going down, go down
      current_floor--;
   }  //end move()
//--------------------------------------------------------------
void elevator::get_destinations()     //stop, get destinations
   {
   char ustring[BUF_LENGTH];          //utility buffer for input
   int dest_floor;                    //destination floor

   set_cursor_pos(1,22); clear_line();  //clear top line
   set_cursor_pos(1, 22);
   cout << "Car " << (car_number+1)
        << " has stopped at floor " << (current_floor+1)
        << "\nEnter destination floors (0 when finished)";
   for(int j=1; j<NUM_FLOORS; j++)    //get floor requests
      {                               //maximum; usually fewer
      set_cursor_pos(1, 24);
      cout << "Destination " << j << ": ";

      cin.get(ustring, BUF_LENGTH);   //(avoid multiple LFs)
      cin.ignore(10, '\n');      //eat chars, including newline
      dest_floor = atoi(ustring);
      set_cursor_pos(1,24); clear_line(); //clear old input line
      if(dest_floor==0)               //if no more requests,
         {                            //clear bottom three lines
         set_cursor_pos(1,22); clear_line();      
         set_cursor_pos(1,23); clear_line();
         set_cursor_pos(1,24); clear_line();
         return;
         }
      --dest_floor;                   //start at 0, not 1
      if(dest_floor==current_floor)   //chose this very floor
         { --j; continue; }           //   so forget it
      //if we're stopped, first choice made sets direction
      if(j==1 && current_dir==STOP)
         current_dir = (dest_floor < current_floor) ? DN : UP;
      destination[dest_floor] = true; //record selection
      dests_display();                //display destinations
      }
   }  //end get_destinations()
//--------------------------------------------------------------
