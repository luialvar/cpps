#include "whatever.hpp"
#include <iostream>
#include <string>

int main(void) {
    int a = 2;
    int b = 3;

    //: for everything that is not inside a class or a namespace
    //if you don't use it it can use another
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    int equalA = 42;
    int equalB = 42;

    std::cout << "min(equalA, equalB) = " << ::min(equalA, equalB) << std::endl;
    std::cout << "max(equalA, equalB) = " << ::max(equalA, equalB) << std::endl;
    return 0;
}
