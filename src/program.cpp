#include "util/typedef.hpp"
#include "chess/definitions/chess_enums.hpp"
#include <iostream>

using namespace std;
using namespace util;
using namespace chess::definitions;

int main() {
    // util::bin::Printer::UllAsBin((ull) 100);
    Square x = Square::D5;
    cout << "\n" << static_cast<ul>(x);
    // cout << x  
    // 
    // 
    return 0;
}