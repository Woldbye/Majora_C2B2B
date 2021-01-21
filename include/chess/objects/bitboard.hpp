#ifndef BITBOARD_HPP
#define BITBOARD_HPP

#include "util/typedef.hpp"
#include "chess/definitions/chess_enums.hpp"

namespace chess
{
  namespace objects
  {
    class Bitboard
    {
      private:
        util::U64 board_;

      public:
        /**
         * Default constructor for bitboard will initialize it as empty.
         *
         * @param board defines the initial board state.
         */
        Bitboard(util::U64 board = 0);
        
        // implicit conversion to ul
        operator util::U64() const;   

        /**
         * set(int i) Sets the bit at the received parameter index 
         * @precondition i > 0 && i <= 32 
         * @param i is the index of the bit to set. Must be in the range 0-63 
         */
        void set(const util::U32 i);

        /**
         * clear(int i) Clears the bit at the received parameter index 
         * @precondition i > 0 && i <= 32
         * @param i is the index of the bit to clear. Must be in the range 0-63 
         */
        void clear(const util::U32 i);

        /**
         * reset() resets the current bitboard to all zeros.
         */
        void reset();

        /**
         * pop() pops the least significant bit in the bitboard (i.e. private var board_)
         * 
         * @return index (0..63) of least significant one bit (LS1B).
         */
        util::U32 pop();  

        /**
         * prints the contained bitboard to console as 8*8 dimensions.
         */
        void print() const;
        
        /**
         * chessPrint() prints the contained bitboard to console with the corresponding ranks and files
         * mapped on the output. 
         */
        void chessPrint() const;

    };

    // ops in .hpp instead of src for inline keyword
    inline
    Bitboard::operator util::U64() const { return Bitboard::board_; }
  }
}
#endif // BITBOARD_HPP 