#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

static void testVector() {
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    std::vector<int>::iterator it = easyfind(numbers, 20);
    std::cout << "vector found: " << *it << std::endl;
    *it = 42;
    std::cout << "vector changed value: " << numbers[1] << std::endl;
}

static void testList() {
    std::list<int> numbers;

    numbers.push_back(3);
    numbers.push_back(6);
    numbers.push_back(9);

    std::cout << "list found: " << *easyfind(numbers, 9) << std::endl;
}

static void testConstDeque() {
    std::deque<int> values;

    values.push_back(1);
    values.push_back(2);
    values.push_back(3);

    const std::deque<int>& constValues = values;
    std::cout << "const deque found: " << *easyfind(constValues, 2) << std::endl;
}

static void testNotFound() {
    std::vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    try {
        easyfind(numbers, 99);
    } catch (std::exception& e) {
        std::cout << "not found test: " << e.what() << std::endl;
    }
}

int main() {
    testVector();
    testList();
    testConstDeque();
    testNotFound();
    return 0;
}
