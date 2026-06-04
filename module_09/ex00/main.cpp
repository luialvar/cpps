#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int main(int argc, char** argv) {
    BitcoinExchange exchange;

    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    try {
        exchange.run(argv[1]);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "." << std::endl;
        return 1;
    }
    return 0;
}
