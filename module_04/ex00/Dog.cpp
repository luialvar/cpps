#include "Dog.hpp"
#include <iostream>

// ------------------ OCF ------------------

Dog::Dog() : Animal() {
    type = "Dog";
    std::cout << "Dog default-constructed\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy-constructed\n";
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Dog copy-assigned\n";
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destroyed\n";
}

// ------------------ Methods ------------------

void Dog::makeSound() const {
    std::cout << "Woof woof!\n";
}
