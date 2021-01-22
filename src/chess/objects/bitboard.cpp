#include "util/typedef.hpp"
#include "chess/objects/bitboard.hpp"
#include "chess/definitions/chess_enums.hpp"
#include <assert.h>
#include <array>
#include <iostream>

using namespace util;
using namespace chess::definitions;
using namespace std;

namespace {
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
  return BRUJIN_ARR[((bb ^ (bb-1)) * BRUJIN_NUM) >> 58];
}
}

namespace chess {
namespace objects {

Bitboard::Bitboard(U64 board) {
  board_ = board;
}

void Bitboard::reset() {
  board_ = 0;
}

void Bitboard::clear(const U32 i) {
  board_ &= ~((U64) 1 << i);
}

void Bitboard::set(const U32 i) {
  board_ |= ((U64) 1 << i);
}

U32 Bitboard::pop() {
  assert ( board_ != 0 );
  // least significant one bit index
  U32 index = bitScanForward(board_);
  clear(index); 
  return index;
}

void Bitboard::print() const {
  string output;
  // copy of board
  U64 board = board_;
  int dimension = sizeof(U64);
  for (U32 i=0; i < 64; ++i)
  {
    output += (board & 1) ? "1 " : "0 ";
    // if i % 8 != 0
    if (!((i+1) % dimension))
    {
      output += "\n";
    }
    board >>= 1;
  }
  std::cout << output << "\n";
}

void Bitboard::chessPrint() const {
  U32 file;
  // file start
  const U32 file_s = static_cast<U32>(File::A);
  // file end
  const U32 file_e = static_cast<U32>(File::H);
  U64 board = board_;
  U32 rank = static_cast<U32>(Rank::_8);
  string output;

  while (rank > 0)
  {
    output += RANK_TO_STR[rank] + " ";
    for (file = file_s; file <= file_e; ++file)
    {
      output += (board & 1) ? "1 " : "0 ";
      board >>= 1;
    }
    output += "\n";
    rank--;
  }
  // file markers
  output += "  ";
  file = file_s;
  while (file <= file_e)
  {
    output += FILE_TO_STR[file];
    output += " ";
    file++;
  }
  std::cout << output << "\n";
}
} // namespace definitions
} // namespace chess