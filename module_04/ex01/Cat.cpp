#include "Cat.hpp"
#include <iostream>

// ------------------ OCF ------------------

Cat::Cat() : Animal(), brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat default-constructed\n";
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Cat copy-constructed\n";
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    std::cout << "Cat copy-assigned\n";
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destroyed\n";
}

// ------------------ Methods ------------------

void Cat::makeSound() const {
    std::cout << "Meow meow!\n";
}

void Cat::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return brain->getIdea(index);
}
