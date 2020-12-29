#include <iostream>
#include "print.hpp"

int main() {
    util::bin::Printer::ULongAsBin((unsigned long long int) 100);
    std::cout << "Hello World!";
    return 0;
}