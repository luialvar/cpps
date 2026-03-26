#include "Animal.hpp"
#include <iostream>

// ------------------ OCF ------------------

Animal::Animal() : type("Animal") {
    std::cout << "Animal default-constructed\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy-constructed\n";
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "Animal copy-assigned\n";
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destroyed\n";
}

// ------------------ Methods ------------------

const std::string& Animal::getType() const {
    return type;
}
