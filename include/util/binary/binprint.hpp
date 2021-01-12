// #pragma once
// namespace util
// {
// 
//   namespace bin
//   {
//     #include "utilities/typedef.hpp"
//     using namespace utilities;
// 
//     class Printer
//     {
//       private:
//         Printer() {}
// 
//       public:
//         /**
//          * ULongAsBin prints the received parameter "num" as it's binary representation
//          * in an 8x8 matrix.
//          * 
//          * @param num is the number to print
//          */
//         inline static void UllAsBin(ull num)
//         {
//           std::string output;
//           int dimension = sizeof(ull);          
//           for (int i=1; i <= dimension * dimension; i++)
//           {
//             num >>= 1;
//             output += (num & 1) ? "1" : "0";
//             
//             if (i != 1 && !(i % dimension))
//             {
//               output += "\n";
//             }
//           }
//           std::cout << output;
//         }
//     };
//   }
// }