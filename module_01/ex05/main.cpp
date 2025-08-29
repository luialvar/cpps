#include "Harl.hpp"
#include <iostream>

int main() {
    Harl h;

    std::cout << "---- DEBUG ----\n";
    h.complain("DEBUG");

    std::cout << "---- INFO ----\n";
    h.complain("INFO");

    std::cout << "---- WARNING ----\n";
    h.complain("WARNING");

    std::cout << "---- ERROR ----\n";
    h.complain("ERROR");

    std::cout << "---- UNKNOWN ----\n";
    h.complain("WHATEVER");

    return 0;
}
