#include "Bureaucrat.hpp"
#include <iostream>

static void testValidBureaucrat() {
    try {
        Bureaucrat bob("Bob", 42);

        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

static void testInvalidHighGrade() {
    try {
        Bureaucrat boss("Boss", 0);
        std::cout << boss << std::endl;
    } catch (std::exception& e) {
        std::cout << "High grade test: " << e.what() << std::endl;
    }
}

static void testInvalidLowGrade() {
    try {
        Bureaucrat intern("Intern", 151);
        std::cout << intern << std::endl;
    } catch (std::exception& e) {
        std::cout << "Low grade test: " << e.what() << std::endl;
    }
}

static void testGradeLimits() {
    try {
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        top.incrementGrade();
    } catch (std::exception& e) {
        std::cout << "Increment limit test: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bottom("Bottom", 150);
        std::cout << bottom << std::endl;
        bottom.decrementGrade();
    } catch (std::exception& e) {
        std::cout << "Decrement limit test: " << e.what() << std::endl;
    }
}

int main() {
    testValidBureaucrat();
    testInvalidHighGrade();
    testInvalidLowGrade();
    testGradeLimits();
    return 0;
}
