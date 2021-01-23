#ifndef BRUJIN_HPP
#define BRUJIN_HPP

#include "util/typedef.hpp"
#include <array>

namespace {
/** 
* bitboard applies De Brujins forward bit scan algorithm for pop.
*/
const util::U64 BRUJIN_NUM = 0x03f79d71b4cb0a89;
// De brujin seq table
const std::array<util::U64, 64> BRUJIN_ARR = {
  0, 47,  1, 56, 48, 27,  2, 60,
  57, 49, 41, 37, 28, 16,  3, 61,
  54, 58, 35, 52, 50, 42, 21, 44,
  38, 32, 29, 23, 17, 11,  4, 62,
  46, 55, 26, 59, 40, 36, 15, 53,
  34, 51, 20, 43, 31, 22, 10, 45,
  25, 39, 14, 33, 19, 30,  9, 24,
  13, 18,  8, 12,  7,  6,  5, 63
};
}

namespace util {
namespace binary {
/**
 * Uses LS1B seperation instead of LS1B isolation (i.e. bb ^ (bb-1) instead of bb & -bb)
 * @param bb value to scan
 * @precondition bb != 0
 * @return index (0..63) of least significant one bit
*/
inline U32 bitScanForward(const util::U64 bb) {
  return BRUJIN_ARR[((bb ^ (bb-1)) * BRUJIN_NUM) >> 58];
}
} // util
} // binary
#endif // BRUJIN_HPP