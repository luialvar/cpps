#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    Base* base;

    std::srand(std::time(NULL));
    for (int i = 0; i < 6; i++) {
        base = generate();
        std::cout << "identify(Base*): ";
        identify(base);
        std::cout << "identify(Base&): ";
        identify(*base);
        delete base;
    }
    return 0;
}
