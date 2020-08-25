// virtshap.cpp
// virtual functions with shapes
#include <iostream>
using namespace std;
#include "msoftcon.h"         //for graphics functions
////////////////////////////////////////////////////////////////
class shape                   //base class
   {
   protected:
      int xCo, yCo;           //coordinates of center
      color fillcolor;        //color
      fstyle fillstyle;       //fill pattern
   public:                    //no-arg constructor
      shape() : xCo(0), yCo(0), fillcolor(cWHITE), 
                                           fillstyle(SOLID_FILL)    
         {  }                 //4-arg constructor                              
      shape(int x, int y, color fc, fstyle fs) :
                    xCo(x), yCo(y), fillcolor(fc), fillstyle(fs)
         {  }
      virtual void draw() = 0 //pure virtual draw function
         {
         set_color(fillcolor);
         set_fill_style(fillstyle);
         }
   };
////////////////////////////////////////////////////////////////
class ball : public shape
   {
   private:
      int radius;             //(xCo, yCo) is center
   public:
      ball() : shape()        //no-arg constr
         {  }
                              //5-arg constructor
      ball(int x, int y, int r, color fc, fstyle fs)
                    : shape(x, y, fc, fs), radius(r)
         {  }
      void draw()             //draw the ball
         {
         shape::draw();
         draw_circle(xCo, yCo, radius);              
         }
   };
////////////////////////////////////////////////////////////////
class rect : public shape
   {
   private:
      int width, height;      //(xCo, yCo) is upper left corner
   public:
      rect() : shape(), height(0), width(0)     //no-arg ctor
         {  }                                   //6-arg ctor
      rect(int x, int y, int h, int w, color fc, fstyle fs) :
                       shape(x, y, fc, fs), height(h), width(w)
         {  }
      void draw()             //draw the rectangle
         {
         shape::draw();
         draw_rectangle(xCo, yCo, xCo+width, yCo+height);
         set_color(cWHITE);   //draw diagonal
         draw_line(xCo, yCo, xCo+width, yCo+height);  
         } 
   };
////////////////////////////////////////////////////////////////
class tria : public shape
   {
   private:
      int height;             //(xCo, yCo) is tip of pyramid
   public:
      tria() : shape(), height(0) //no-arg constructor
         { }                  //5-arg constructor
      tria(int x, int y, int h, color fc, fstyle fs) :
                                 shape(x, y, fc, fs), height(h) 
         {  }
      void draw()             //draw the triangle
         {
         shape::draw();
         draw_pyramid(xCo, yCo, height);
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   int j;
   init_graphics();             //initialize graphics system

   shape* pShapes[3];           //array of pointers to shapes
                                //define three shapes
   pShapes[0] = new ball(40, 12, 5, cBLUE, X_FILL);        
   pShapes[1] = new rect(12, 7, 10, 15, cRED, SOLID_FILL);
   pShapes[2] = new tria(60, 7,  11, cGREEN, MEDIUM_FILL);

   for(j=0; j<3; j++)           //draw all shapes
      pShapes[j]->draw();

   for(j=0; j<3; j++)           //delete all shapes 
      delete pShapes[j];                 
   set_cursor_pos(1, 25);
   return 0;
   }
