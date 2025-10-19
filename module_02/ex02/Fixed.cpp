#include "Fixed.hpp"
#include <iostream> // prints y operator<<
#include <cmath>    // roundf
#include <cstdint>  // int64_t

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
Fixed::Fixed(const int n) : value(n << fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
: value(static_cast<int>(roundf(f * static_cast<float>(1 << fractionalBits))))) {
    std::cout << "Float constructor called" << std::endl;
}

// --- Acceso crudo ---
int Fixed::getRawBits() const { return value; }
void Fixed::setRawBits(int raw) { value = raw; }

// --- Conversiones ---
float Fixed::toFloat() const {
    return static_cast<float>(value) / static_cast<float>(1 << fractionalBits);
}

int Fixed::toInt() const { return value >> fractionalBits; }

// --- Operadores de comparación ---
bool Fixed::operator>(const Fixed& rhs) const { return value >  rhs.value; }
bool Fixed::operator<(const Fixed& rhs) const { return value <  rhs.value; }
bool Fixed::operator>=(const Fixed& rhs) const { return value >= rhs.value; }
bool Fixed::operator<=(const Fixed& rhs) const { return value <= rhs.value; }
bool Fixed::operator==(const Fixed& rhs) const { return value == rhs.value; }
bool Fixed::operator!=(const Fixed& rhs) const { return value != rhs.value; }

// --- Operadores aritméticos ---
Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed r; r.value = this->value + rhs.value; return r;
}
Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed r; r.value = this->value - rhs.value; return r;
}
Fixed Fixed::operator*(const Fixed& rhs) const {
    // (a * b) / 2^fb  -> usar 64-bit para evitar overflow
    int64_t prod = static_cast<int64_t>(this->value) * static_cast<int64_t>(rhs.value);
    Fixed r;
    // redondeo al más cercano: añadir 2^(fb-1) antes de desplazar (para valores positivos)
    if (prod >= 0)
        r.value = static_cast<int>((prod + (static_cast<int64_t>(1) << (fractionalBits - 1)))
                                   >> fractionalBits);
    else
        r.value = static_cast<int>((prod - (static_cast<int64_t>(1) << (fractionalBits - 1)))
                                   >> fractionalBits);
    return r;
}
Fixed Fixed::operator/(const Fixed& rhs) const {
    // (a / b) * 2^fb  -> desplazar el numerador antes de dividir
    // Si rhs.value == 0 -> comportamiento indefinido (permitido que crashee)
    int64_t num = (static_cast<int64_t>(this->value) << fractionalBits);
    int64_t q   = num / static_cast<int64_t>(rhs.value);
    Fixed r; r.value = static_cast<int>(q); return r;
}

// --- ++ / -- ---
Fixed& Fixed::operator++() {            // pre
    ++value; return *this;
}
Fixed  Fixed::operator++(int) {         // post
    Fixed tmp(*this); ++(*this); return tmp;
}
Fixed& Fixed::operator--() {            // pre
    --value; return *this;
}
Fixed  Fixed::operator--(int) {         // post
    Fixed tmp(*this); --(*this); return tmp;
}

// --- min / max ---
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a.value <= b.value) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a.value <= b.value) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a.value >= b.value) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a.value >= b.value) ? a : b;
}

// --- Salida ---
std::ostream& operator<<(std::ostream& os, const Fixed& x) {
    return os << x.toFloat();
}
