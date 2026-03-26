#include "Cat.hpp"
#include <iostream>

// ------------------ OCF ------------------

Cat::Cat() : Animal() {
    type = "Cat";
    std::cout << "Cat default-constructed\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy-constructed\n";
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Cat copy-assigned\n";
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destroyed\n";
}

// ------------------ Methods ------------------

void Cat::makeSound() const {
    std::cout << "Meow meow!\n";
}
