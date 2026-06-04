#ifndef SPAN_TPP
#define SPAN_TPP

#include <iterator>

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    typename std::iterator_traits<Iterator>::difference_type distance;

    distance = std::distance(begin, end);
    if (distance < 0 || this->numbers.size() + static_cast<unsigned int>(distance) > this->maxSize) {
        throw SpanFullException();
    }
    this->numbers.insert(this->numbers.end(), begin, end);
}

#endif
