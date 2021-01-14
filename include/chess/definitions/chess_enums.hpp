#ifndef CHESS_ENUMS_HPP
#define CHESS_ENUMS_HPP

#include "util/typedef.hpp"
#include <string>

namespace chess
{
    namespace definitions
    {
        extern const util::ul BOARD_SIZE; // TO:DO move to another file

        enum class Piece : util::byte
        {
            None,
            wP,
            wN,
            wB,
            wR,
            wQ,
            wK,
            bP,
            bN,
            bB,
            bR,
            bQ,
            bK,
            Count = bK + 1
        };
      

        // The file on the board (a-h)
        enum class File : util::byte
        {
            None,
            A,
            B,
            C,
            D,
            E,
            F,
            G,
            H,
            Count = H + 1 // 9
        };


        // the ranks on the board (1-8).
        enum class Rank : util::byte 
        {
            None,
            _1,
            _2,
            _3,
            _4,
            _5,
            _6,
            _7,
            _8,
            Count = _8 + 1
        };

        // colours of the game.
        enum class Colour : util::byte 
        {
            None,
            White,
            Black,
            Both,
            Count = Both + 1
        };

        enum class Square : util::byte 
        {
            None = 0,
            A1 = 21,
            B1,
            C1,
            D1,
            E1,
            F1,
            G1,
            H1,
            A2 = 31,
            B2,
            C2,
            D2,
            E2,
            F2,
            G2,
            H2,
            A3 = 41,
            B3,
            C3,
            D3,
            E3,
            F3,
            G3,
            H3,
            A4 = 51,
            B4,
            C4,
            D4,
            E4,
            F4,
            G4,
            H4,
            A5 = 61,
            B5,
            C5,
            D5,
            E5,
            F5,
            G5,
            H5,
            A6 = 71,
            B6,
            C6,
            D6,
            E6,
            F6,
            G6,
            H6,
            A7 = 81,
            B7,
            C7,
            D7,
            E7,
            F7,
            G7,
            H7,
            A8 = 91,
            B8,
            C8,
            D8,
            E8,
            F8,
            G8,
            H8,
            Count = H8 + 1
        };

        // Enum to str arrays
        extern const std::string PIECE_TO_STR[static_cast<util::ul>(Piece::Count)];
        extern const std::string FILE_TO_STR[static_cast<util::ul>(File::Count)];
        extern const std::string RANK_TO_STR[static_cast<util::ul>(Rank::Count)];
        extern const std::string COLOUR_TO_STR[static_cast<util::ul>(Rank::Count)];
        extern const std::string* SQUARE_TO_STR;
    }
}
#endif // CHESS_ENUMS_HPP