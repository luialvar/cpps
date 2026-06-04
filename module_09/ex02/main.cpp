#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int main(int argc, char** argv) {
    PmergeMe sorter;

    try {
        sorter.run(argc, argv);
    } catch (std::exception& e) {
        (void)e;
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
