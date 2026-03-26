#include "Dog.hpp"
#include <iostream>

// ------------------ OCF ------------------

Dog::Dog() : Animal(), brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog default-constructed\n";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copy-constructed\n";
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    std::cout << "Dog copy-assigned\n";
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed\n";
}

// ------------------ Methods ------------------

void Dog::makeSound() const {
    std::cout << "Woof woof!\n";
}

void Dog::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}
