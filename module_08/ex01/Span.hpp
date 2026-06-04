#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

class Span {
private:
    unsigned int     maxSize;
    std::vector<int> numbers;

public:
    // ------------------ Exceptions ------------------

    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NotEnoughNumbersException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    // ------------------ OCF ------------------

    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    // ------------------ Methods ------------------

    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end);
};

#include "Span.tpp"

#endif
