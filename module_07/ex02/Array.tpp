#ifndef ARRAY_TPP
#define ARRAY_TPP

// ------------------ Exceptions ------------------

//remember throw is to not launch exceptions
template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    return "array index is out of bounds";
}

// ------------------ OCF ------------------

template <typename T>
Array<T>::Array() : elements(NULL), length(0) {
}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), length(n) {
}

template <typename T>
Array<T>::Array(const Array& other) : elements(NULL), length(other.length) {
    if (this->length > 0) {
        this->elements = new T[this->length]();
        for (unsigned int i = 0; i < this->length; i++) {
            this->elements[i] = other.elements[i];
        }
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    T* newElements = NULL;

    if (this != &other) {
        if (other.length > 0) {
            newElements = new T[other.length]();
            for (unsigned int i = 0; i < other.length; i++) {
                newElements[i] = other.elements[i];
            }
        }
        delete[] this->elements;
        this->elements = newElements;
        this->length = other.length;
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] this->elements;
}

// ------------------ Getters ------------------

template <typename T>
unsigned int Array<T>::size() const {
    return this->length;
}

// ------------------ Operators ------------------

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= this->length) {
        throw OutOfBoundsException();
    }
    return this->elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= this->length) {
        throw OutOfBoundsException();
    }
    return this->elements[index];
}

#endif
