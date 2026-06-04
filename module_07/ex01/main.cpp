#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement(const T& element) {
    std::cout << element << std::endl;
}

void incrementInt(int& number) {
    number++;
}

void addExclamation(std::string& text) {
    text += "!";
}

int main() {
    int numbers[4] = {1, 2, 3, 4};
    const double decimals[3] = {1.1, 2.2, 3.3};
    std::string words[3] = {"hello", "templates", "iter"};

    std::cout << "Numbers:" << std::endl;
    ::iter(numbers, 4, printElement<int>);

    ::iter(numbers, 4, incrementInt);
    std::cout << "Incremented numbers:" << std::endl;
    ::iter(numbers, 4, printElement<int>);

    std::cout << "Const decimals:" << std::endl;
    ::iter(decimals, 3, printElement<double>);

    ::iter(words, 3, addExclamation);
    std::cout << "Words:" << std::endl;
    ::iter(words, 3, printElement<std::string>);
    return 0;
}
