#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int main(int argc, char** argv) {
    BitcoinExchange exchange;

    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    try {
        exchange.run(argv[1]);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << "." << std::endl;
        return 1;
    }
    return 0;
}
