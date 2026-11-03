#include "Array.hpp"
#include <iostream>
#include <string>

static void testIntArray() {
    Array<int> numbers(5);

    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = static_cast<int>(i * 10);
    }
    std::cout << "numbers size: " << numbers.size() << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << std::endl;
    }
}

static void testDeepCopy() {
    Array<std::string> original(2);

    original[0] = "original zero";
    original[1] = "original one";

    Array<std::string> copy(original);
    copy[0] = "copy zero";

    std::cout << "original[0]: " << original[0] << std::endl;
    std::cout << "copy[0]: " << copy[0] << std::endl;
}

static void testAssignment() {
    Array<int> first(3);
    Array<int> second;

    first[0] = 1;
    first[1] = 2;
    first[2] = 3;
    second = first;
    second[1] = 42;

    std::cout << "first[1]: " << first[1] << std::endl;
    std::cout << "second[1]: " << second[1] << std::endl;
}

static void testOutOfBounds() {
    Array<int> numbers(2);

    try {
        std::cout << numbers[2] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

static void testEmptyArray() {
    Array<int> empty;

    std::cout << "empty size: " << empty.size() << std::endl;
    try {
        empty[0] = 1;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    testIntArray();
    testDeepCopy();
    testAssignment();
    testOutOfBounds();
    testEmptyArray();
    return 0;
}
