                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                // circles.cpp
// circles as graphics objects
#include "msoftcon.h"         // for graphics functions
////////////////////////////////////////////////////////////////
class circle                  //graphics circle
   {
   protected:
      int xCo, yCo;           //coordinates of center
      int radius;             
      color fillcolor;        //color
      fstyle fillstyle;       //fill pattern
   public:                    //sets circle attributes
      void set(int x, int y, int r, color fc, fstyle fs)
         {
         xCo = x;
         yCo = y;
         radius = r;
         fillcolor = fc;
         fillstyle = fs;
         }
      void draw()             //draws the circle                          
         {
         set_color(fillcolor);              //set color
         set_fill_style(fillstyle);         //set fill
         draw_circle(xCo, yCo, radius);     //draw solid circle            
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   init_graphics();           //initialize graphics system

   circle c1;                 //create circles
   circle c2; 
   circle c3;
                              //set circle attributes
   c1.set(15, 7, 5, cBLUE, X_FILL);
   c2.set(41, 12, 7, cRED, O_FILL);
   c3.set(65, 18, 4, cGREEN, MEDIUM_FILL);

   c1.draw();                 //draw circles
   c2.draw();
   c3.draw();
   set_cursor_pos(1, 25);     //lower left corner
   return 0;
   }
