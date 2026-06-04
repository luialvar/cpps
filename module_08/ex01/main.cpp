#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

static void testSubjectExample() {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "subject shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "subject longest: " << sp.longestSpan() << std::endl;
}

static void testTooFewNumbers() {
    Span sp(1);

    sp.addNumber(42);
    try {
        sp.shortestSpan();
    } catch (std::exception& e) {
        std::cout << "too few numbers: " << e.what() << std::endl;
    }
}

static void testFullSpan() {
    Span sp(2);

    try {
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
    } catch (std::exception& e) {
        std::cout << "full span: " << e.what() << std::endl;
    }
}

static void testRangeInsert() {
    std::vector<int> values;
    Span             sp(10000);

    for (int i = 0; i < 10000; i++) {
        values.push_back(i * 2);
    }
    sp.addNumbers(values.begin(), values.end());
    std::cout << "range shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "range longest: " << sp.longestSpan() << std::endl;
}

static void testNegativeNumbers() {
    Span sp(4);

    sp.addNumber(-10);
    sp.addNumber(-3);
    sp.addNumber(8);
    sp.addNumber(20);
    std::cout << "negative shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "negative longest: " << sp.longestSpan() << std::endl;
}

int main() {
    std::srand(std::time(NULL));
    testSubjectExample();
    testTooFewNumbers();
    testFullSpan();
    testRangeInsert();
    testNegativeNumbers();
    return 0;
}
