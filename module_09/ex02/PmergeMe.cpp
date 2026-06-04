#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>

// ------------------ OCF ------------------

PmergeMe::PmergeMe() : sortedVector(), sortedDeque(), vectorTime(0), dequeTime(0) {
}

PmergeMe::PmergeMe(const PmergeMe& other)
    : sortedVector(other.sortedVector),
      sortedDeque(other.sortedDeque),
      vectorTime(other.vectorTime),
      dequeTime(other.dequeTime) {
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->sortedVector = other.sortedVector;
        this->sortedDeque = other.sortedDeque;
        this->vectorTime = other.vectorTime;
        this->dequeTime = other.dequeTime;
    }
    return *this;
}

PmergeMe::~PmergeMe() {
}

// ------------------ Helpers ------------------

int PmergeMe::parsePositiveInteger(const std::string& value) const {
    char* end;
    long  number;

    errno = 0;
    number = std::strtol(value.c_str(), &end, 10);
    if (value.empty() || *end != '\0' || errno == ERANGE || number <= 0 || number > INT_MAX) {
        throw std::runtime_error("invalid positive integer");
    }
    return static_cast<int>(number);
}

void PmergeMe::printSequence(char** argv, int argc) const {
    for (int i = 1; i < argc; i++) {
        std::cout << argv[i];
        if (i + 1 < argc) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void PmergeMe::printVector(const std::vector<int>& values) const {
    for (std::vector<int>::const_iterator it = values.begin(); it != values.end(); ++it) {
        std::cout << *it;
        if (it + 1 != values.end()) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

std::vector<int> PmergeMe::buildVector(int argc, char** argv) const {
    std::vector<int> values;

    values.reserve(argc - 1);
    for (int i = 1; i < argc; i++) {
        values.push_back(this->parsePositiveInteger(argv[i]));
    }
    return values;
}

std::deque<int> PmergeMe::buildDeque(int argc, char** argv) const {
    std::deque<int> values;

    for (int i = 1; i < argc; i++) {
        values.push_back(this->parsePositiveInteger(argv[i]));
    }
    return values;
}

std::vector<unsigned int> PmergeMe::buildJacobsthalOrderVector(unsigned int size) const {
    std::vector<unsigned int> order;
    unsigned int              previous = 1;
    unsigned int              current = 3;

    if (size == 0) {
        return order;
    }
    order.push_back(0);
    while (previous < size) {
        unsigned int limit = current;

        if (limit > size) {
            limit = size;
        }
        for (unsigned int i = limit; i > previous; i--) {
            order.push_back(i - 1);
        }
        unsigned int next = current + 2 * previous;

        previous = current;
        current = next;
    }
    return order;
}

std::deque<unsigned int> PmergeMe::buildJacobsthalOrderDeque(unsigned int size) const {
    std::deque<unsigned int> order;
    unsigned int             previous = 1;
    unsigned int             current = 3;

    if (size == 0) {
        return order;
    }
    order.push_back(0);
    while (previous < size) {
        unsigned int limit = current;

        if (limit > size) {
            limit = size;
        }
        for (unsigned int i = limit; i > previous; i--) {
            order.push_back(i - 1);
        }
        unsigned int next = current + 2 * previous;

        previous = current;
        current = next;
    }
    return order;
}

void PmergeMe::binaryInsertVector(std::vector<int>& values, int number) const {
    unsigned int low = 0;
    unsigned int high = values.size();

    while (low < high) {
        unsigned int middle = low + (high - low) / 2;

        if (number < values[middle]) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }
    values.insert(values.begin() + low, number);
}

void PmergeMe::binaryInsertDeque(std::deque<int>& values, int number) const {
    unsigned int low = 0;
    unsigned int high = values.size();

    while (low < high) {
        unsigned int middle = low + (high - low) / 2;

        if (number < values[middle]) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }
    values.insert(values.begin() + low, number);
}

std::vector<int> PmergeMe::mergeInsertSortVector(const std::vector<int>& values) const {
    std::vector<int> larger;
    std::vector<int> pending;
    std::vector<int> sorted;
    std::vector<unsigned int> order;

    if (values.size() < 2) {
        return values;
    }
    larger.reserve(values.size() / 2);
    pending.reserve((values.size() + 1) / 2);
    for (std::size_t i = 0; i + 1 < values.size(); i += 2) {
        if (values[i] < values[i + 1]) {
            pending.push_back(values[i]);
            larger.push_back(values[i + 1]);
        } else {
            pending.push_back(values[i + 1]);
            larger.push_back(values[i]);
        }
    }
    if (values.size() % 2 != 0) {
        pending.push_back(values[values.size() - 1]);
    }
    sorted = this->mergeInsertSortVector(larger);
    order = this->buildJacobsthalOrderVector(pending.size());
    for (std::vector<unsigned int>::const_iterator it = order.begin(); it != order.end(); ++it) {
        this->binaryInsertVector(sorted, pending[*it]);
    }
    return sorted;
}

std::deque<int> PmergeMe::mergeInsertSortDeque(const std::deque<int>& values) const {
    std::deque<int> larger;
    std::deque<int> pending;
    std::deque<int> sorted;
    std::deque<unsigned int> order;

    if (values.size() < 2) {
        return values;
    }
    for (std::size_t i = 0; i + 1 < values.size(); i += 2) {
        if (values[i] < values[i + 1]) {
            pending.push_back(values[i]);
            larger.push_back(values[i + 1]);
        } else {
            pending.push_back(values[i + 1]);
            larger.push_back(values[i]);
        }
    }
    if (values.size() % 2 != 0) {
        pending.push_back(values[values.size() - 1]);
    }
    sorted = this->mergeInsertSortDeque(larger);
    order = this->buildJacobsthalOrderDeque(pending.size());
    for (std::deque<unsigned int>::const_iterator it = order.begin(); it != order.end(); ++it) {
        this->binaryInsertDeque(sorted, pending[*it]);
    }
    return sorted;
}

// ------------------ Methods ------------------

void PmergeMe::run(int argc, char** argv) {
    std::clock_t start;
    std::clock_t end;
    std::vector<int> vectorValues;
    std::deque<int>  dequeValues;

    if (argc < 2) {
        throw std::runtime_error("missing sequence");
    }
    for (int i = 1; i < argc; i++) {
        this->parsePositiveInteger(argv[i]);
    }
    start = std::clock();
    vectorValues = this->buildVector(argc, argv);
    this->sortedVector = this->mergeInsertSortVector(vectorValues);
    end = std::clock();
    this->vectorTime = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;

    start = std::clock();
    dequeValues = this->buildDeque(argc, argv);
    this->sortedDeque = this->mergeInsertSortDeque(dequeValues);
    end = std::clock();
    this->dequeTime = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;

    std::cout << "Before: ";
    this->printSequence(argv, argc);
    std::cout << "After: ";
    this->printVector(this->sortedVector);
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << this->sortedVector.size()
              << " elements with std::vector : " << this->vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << this->sortedDeque.size()
              << " elements with std::deque : " << this->dequeTime << " us" << std::endl;
}
