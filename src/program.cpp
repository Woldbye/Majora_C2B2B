#include "init.hpp"
#include "util/typedef.hpp"
#include "chess/definitions/chess_enums.hpp"
#include <iostream>

using namespace std;
using namespace util;
using namespace chess::definitions;


int main() {
    // util::bin::Printer::UllAsBin((ull) 100);
    Init init = Init();
    init.initAll();

    for (ul i = 0; i < BOARD_SIZE; i++)
        cout << SQUARE_TO_STR[i] << endl;

    // cout << x  
    // 
    // 
    return 0;
}