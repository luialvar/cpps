#include "Fixed.hpp"
#include <iostream> // para los prints y operator<<
#include <cmath>    // roundf

// Definición del miembro estático (C++98)
const int Fixed::fractionalBits = 8;

// --- OCF ---
Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value(other.value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// --- ex01: constructores de conversión ---
Fixed::Fixed(const int n) : value(n << fractionalBits) {//this move to the side fractional bits slides
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
: value(static_cast<int>(roundf(f * (1 << fractionalBits)))) { //1 << fractionalBits is 256
    std::cout << "Float constructor called" << std::endl;
}

// --- Acceso crudo ---
int Fixed::getRawBits() const {
    return value;
}

void Fixed::setRawBits(int raw) {
    value = raw;
}

// --- Conversiones ---
float Fixed::toFloat() const {
    return static_cast<float>(value) / static_cast<float>(1 << fractionalBits);
}

int Fixed::toInt() const {
    return value >> fractionalBits;
}

// --- Salida ---
std::ostream& operator<<(std::ostream& os, const Fixed& x) {
    return os << x.toFloat();
}
