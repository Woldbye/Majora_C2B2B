namespace CPPUtilities
{
  #define ull unsigned long long int

  namespace Binary
  {
    #include <iostream> 
    using namespace std; 

    class Printer
    {
      private:
        Printer() {}

      public:
        /**
         * ULongAsBin prints the received parameter "num" as it's binary representation
         * in an 8x8 matrix.
         * 
         * @param num is the number to print
         */
        static void ULongAsBin(unsigned long long int num)
        {
          /*
          int const row,col = 8;

          for (int i=0; i < sizeof(num)*8; i++)
          {

          }
          */
          std::cout << "Hello World!";
        }
    }
  }
}