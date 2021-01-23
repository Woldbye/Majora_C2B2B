#ifndef BITBOARD_HPP
#define BITBOARD_HPP

#include "util/typedef.hpp"
#include "chess/definitions/chess_enums.hpp"
#include "util/binary/brujin.hpp"
#include <assert.h>

namespace chess {
namespace objects {
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
     * @precondition bb != 0
     * @return index (0..63) of least significant one bit
     * @return index (0..63) of least significant one bit
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

// --- Inline functions --- //
inline
Bitboard::operator util::U64() const { return Bitboard::board_; }

// Binary operations:
inline
void Bitboard::reset() {
  board_ = 0;
}

inline 
void Bitboard::clear(const util::U32 i) {
  board_ &= ~((util::U64) 1 << i);
}

inline 
void Bitboard::set(const util::U32 i) {
  board_ |= ((util::U64) 1 << i);
}

inline 
util::U32 Bitboard::pop() {
  assert(board_ != 0);
  // index of the least significant one bit. 
  util::U32 index = util::binary::bitScanForward(board_);
  clear(index); 
  return index;
}
} // namespace objects
} // namespace chess
#endif // BITBOARD_HPP 