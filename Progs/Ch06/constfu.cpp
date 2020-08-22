//constfu.cpp
//demonstrates const member functions

class aClass
   {
   private:
      int alpha;
   public:
      void nonFunc()        //non-const member function
         { alpha = 99; }    //OK

      void conFunc() const  //const member function
         { alpha = 99; }    //error: can't modify a member         
   };
