#include "Fixed.hpp"
#include <iostream>


// Constructor por defecto
Fixed::Fixed() : value(0) 
{
		std::cout << "Default constructor called" << "\n";
}

// Constructor de copia
Fixed::Fixed(const Fixed& other) : value(other.value) 
{
	std::cout << "Copy constructor called" << "\n";
}

// Asignación
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << "\n";
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << "\n";
}

// Get/Set raw
int Fixed::getRawBits(void) const {
		std::cout << "getRawBits member function called" << "\n";
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}
