#include "Span.hpp"
#include <algorithm>
#include <limits>

// ------------------ Exceptions ------------------

const char* Span::SpanFullException::what() const throw() {
    return "span is full";
}

const char* Span::NotEnoughNumbersException::what() const throw() {
    return "not enough numbers to calculate a span";
}

// ------------------ OCF ------------------

Span::Span() : maxSize(0), numbers() {
}

Span::Span(unsigned int n) : maxSize(n), numbers() {
    this->numbers.reserve(n);
}

Span::Span(const Span& other) : maxSize(other.maxSize), numbers(other.numbers) {
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->maxSize = other.maxSize;
        this->numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {
}

// ------------------ Methods ------------------

void Span::addNumber(int number) {
    if (this->numbers.size() >= this->maxSize) {
        throw SpanFullException();
    }
    this->numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    std::vector<int> sortedNumbers;
    unsigned int     shortest;

    if (this->numbers.size() < 2) {
        throw NotEnoughNumbersException();
    }
    sortedNumbers = this->numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    shortest = std::numeric_limits<unsigned int>::max();
    for (std::vector<int>::const_iterator it = sortedNumbers.begin() + 1;
         it != sortedNumbers.end();
         ++it) {
        unsigned int distance = static_cast<unsigned int>(
            static_cast<long>(*it) - static_cast<long>(*(it - 1)));
        if (distance < shortest) {
            shortest = distance;
        }
    }
    return shortest;
}

unsigned int Span::longestSpan() const {
    std::vector<int>::const_iterator minIt;
    std::vector<int>::const_iterator maxIt;

    if (this->numbers.size() < 2) {
        throw NotEnoughNumbersException();
    }
    minIt = std::min_element(this->numbers.begin(), this->numbers.end());
    maxIt = std::max_element(this->numbers.begin(), this->numbers.end());
    return static_cast<unsigned int>(static_cast<long>(*maxIt) - static_cast<long>(*minIt));
}
