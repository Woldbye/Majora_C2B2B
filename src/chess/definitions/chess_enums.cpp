#include "chess/definitions/chess_enums.hpp"
#include "util/typedef.hpp"
#include <string>

using namespace util;
using namespace std;

namespace chess {

    namespace definitions {
        const ul BOARD_SIZE = 120;
        
        // Enum to str arrays
        const string PIECE_TO_STR[static_cast<ul>(Piece::Count)] = {  "None",
                                                                      "wP", "wN", "wB", "wR", "wQ", "wK",
                                                                      "bP", "bN", "bB", "bR", "bQ", "bK" };
        const string FILE_TO_STR[static_cast<ul>(File::Count)] = {
          "None",
          "A", "B", "C", "D", "E", "F", "G", "H"
        };
        
        const string RANK_TO_STR[static_cast<ul>(Rank::Count)] = {
          "None",
          "1", "2", "3", "4", "5", "6", "7", "8"
        };

        const string COLOUR_TO_STR[static_cast<ul>(Rank::Count)] = {
          "None",
          "White", "Black", "Both"
        };

        string* initSquareToString() {
            const ul size = static_cast<ul>(Square::H8);

            static string squares[BOARD_SIZE];

            ul i = 0;
            
            for (; i < 21; i++) { // Sets first 21 to "None"
              squares[i] = "None";
            }
            
            for (; i < size + 1; i++) {
              ul file = i % 10; // Get file

              if (file > 8 || file == 0) {
                squares[i] = "None";
                continue;
              }

              ul rank = i / 10 - 1; // Divide with 10, floor val

              string square = FILE_TO_STR[file] + RANK_TO_STR[rank];
              squares[i] = square;
            }

            for (; i < BOARD_SIZE; i++) {
              squares[i] = "None";
            }

            return squares;
        }

        const string *SQUARE_TO_STR = initSquareToString();

    }
}