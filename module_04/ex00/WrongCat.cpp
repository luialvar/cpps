#include "WrongCat.hpp"
#include <iostream>

// ------------------ OCF ------------------

WrongCat::WrongCat() : WrongAnimal() {
    type = "WrongCat";
    std::cout << "WrongCat default-constructed\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copy-constructed\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    std::cout << "WrongCat copy-assigned\n";
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed\n";
}

// ------------------ Methods ------------------

void WrongCat::makeSound() const {
    std::cout << "WrongCat meows... badly!\n";
}
