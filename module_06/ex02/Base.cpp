#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

// ------------------ Base ------------------

Base::~Base() {
}

// ------------------ Functions ------------------

Base* generate(void) {
    int randomValue = std::rand() % 3;

    if (randomValue == 0) {
        std::cout << "Generated A" << std::endl;
        return new A;
    }
    if (randomValue == 1) {
        std::cout << "Generated B" << std::endl;
        return new B;
    }
    std::cout << "Generated C" << std::endl;
    return new C;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception& e) {
        (void)e;
    }
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception& e) {
        (void)e;
    }
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception& e) {
        (void)e;
    }
    std::cout << "Unknown" << std::endl;
}
