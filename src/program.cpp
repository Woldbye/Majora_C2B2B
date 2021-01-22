#include "init.hpp"
#include "util/typedef.hpp"
#include "chess/definitions/chess_enums.hpp"
#include "chess/objects/bitboard.hpp"
#include <iostream>


using namespace std;
using namespace util;
using namespace chess::definitions;
using namespace chess::objects;


int main() {
    // util::bin::Printer::UllAsBin((ull) 100);
    Init init = Init();
    init.initAll();
    Bitboard board = Bitboard();
    std::cout << "1 << 0: " << (1 << 0) << "\n";
    std::cout << "board val:" << board << "\n";
    board.set(63);
    board.print();
    board.chessPrint();
    std::cout << "popped from board: " << board.pop() << "\n";
    board.chessPrint();
    /*
    for (U32 i = 0; i < BOARD_SIZE; i++)
        cout << SQUARE_TO_STR[i] << endl;
      */
    // cout << x  
    // 
    // 
    return 0;
}