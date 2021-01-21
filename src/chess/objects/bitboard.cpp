#include "util/typedef.hpp"
#include "chess/objects/bitboard.hpp"
#include "chess/definitions/chess_enums.hpp"
#include <assert.h>
#include <array>

using namespace util;
using namespace chess::definitions;
using namespace std;

namespace chess 
{
  namespace objects 
  {
    /** 
     * bitboard applies De Brujins forward bit scan algorithm for pop.
    */
    const U64 BRUJIN_NUM = 0x03f79d71b4cb0a89;
    // De brujin seq table
    const array<U64, 64> BRUJIN_ARR = {
      0, 47,  1, 56, 48, 27,  2, 60,
      57, 49, 41, 37, 28, 16,  3, 61,
      54, 58, 35, 52, 50, 42, 21, 44,
      38, 32, 29, 23, 17, 11,  4, 62,
      46, 55, 26, 59, 40, 36, 15, 53,
      34, 51, 20, 43, 31, 22, 10, 45,
      25, 39, 14, 33, 19, 30,  9, 24,
      13, 18,  8, 12,  7,  6,  5, 63
    };

    /**
     * Uses LS1B seperation instead of LS1B isolation (i.e. bb ^ (bb-1) instead of bb & -bb)
     * @param bb value to scan
     * @precondition bb != 0
     * @return index (0..63) of least significant one bit
    */
    U32 bitScanForward(const U64 bb) {
      assert (bb != 0);
      return BRUJIN_ARR[((bb ^ (bb-1)) * BRUJIN_NUM) >> 58];
    }

    Bitboard::Bitboard(U64 board) {
      board_ = board;
    }

    void Bitboard::reset() {
      board_ = 0;
    }

    void Bitboard::clear(const U32 i) {
      board_ &= -(1 << i);
    }
    
    void Bitboard::set(const U32 i) {
      board_ |= (1 << i);
    }
    
    U32 Bitboard::pop() {
      return -1;
    }

  }
}
