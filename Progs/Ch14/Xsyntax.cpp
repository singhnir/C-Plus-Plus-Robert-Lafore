// xsyntax.cpp
// not a working program
////////////////////////////////////////////////////////////////
class AClass                     // a class
   {
   public:
   class AnError                 // exception class
      {
      };
   void Func()                   // a member function
      {
      if( /* error condition */ )
         throw AnError();        // throw exception
      }
   };
////////////////////////////////////////////////////////////////
int main()                       // application
   {
   try                           // try block
      {
      AClass obj1;               // interact with AClass objects
      obj1.Func();               // may cause error
      }
   catch(AClass::AnError)        // exception handler
      {                          // (catch block)
      }
   return 0;
   }
