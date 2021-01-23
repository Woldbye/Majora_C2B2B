#include "util/typedef.hpp"
#include "chess/objects/bitboard.hpp"
#include "chess/definitions/chess_enums.hpp"
#include <assert.h>
#include <array>
#include <iostream>

using namespace util;
using namespace chess::definitions;
using namespace std;

namespace chess {
namespace objects {
Bitboard::Bitboard(U64 board) {
  board_ = board;
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