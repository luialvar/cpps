#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array {
private:
    T*           elements;
    unsigned int length;

public:
    // ------------------ Exceptions ------------------

    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    // ------------------ OCF ------------------

    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    // ------------------ Getters ------------------

    unsigned int size() const;

    // ------------------ Operators ------------------

    T&       operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
};

#include "Array.tpp"

#endif
