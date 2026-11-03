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
    std::size_t start = !value.empty() && value[0] == '+' ? 1 : 0;

    if (start == value.size()) {
        throw std::runtime_error("invalid positive integer");
    }
    for (std::size_t i = start; i < value.size(); i++) {
        if (value[i] < '0' || value[i] > '9') {
            throw std::runtime_error("invalid positive integer");
        }
    }

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

unsigned int PmergeMe::binaryInsertVector(std::vector<unsigned int>& chain,
    const std::vector<int>& values, unsigned int number, unsigned int high) const {
    unsigned int low = 0;

    while (low < high) {
        unsigned int middle = low + (high - low) / 2;

        if (values[number] < values[chain[middle]]) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }
    chain.insert(chain.begin() + low, number);
    return low;
}

unsigned int PmergeMe::binaryInsertDeque(std::deque<unsigned int>& chain,
    const std::deque<int>& values, unsigned int number, unsigned int high) const {
    unsigned int low = 0;

    while (low < high) {
        unsigned int middle = low + (high - low) / 2;

        if (values[number] < values[chain[middle]]) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }
    chain.insert(chain.begin() + low, number);
    return low;
}

std::vector<unsigned int> PmergeMe::sortVectorIndices(const std::vector<int>& values) const {
    std::vector<int> larger;
    std::vector<unsigned int> smaller;
    std::vector<unsigned int> maxima;
    std::vector<unsigned int> sortedPairs;
    std::vector<unsigned int> chain;
    std::vector<unsigned int> pending;
    std::vector<unsigned int> partners;
    std::vector<unsigned int> order;

    if (values.size() < 2) {
        if (!values.empty()) {
            chain.push_back(0);
        }
        return chain;
    }
    larger.reserve(values.size() / 2);
    smaller.reserve(values.size() / 2);
    maxima.reserve(values.size() / 2);
    chain.reserve(values.size());
    pending.reserve((values.size() + 1) / 2);
    partners.reserve(values.size() / 2);
    for (unsigned int i = 0; i + 1 < values.size(); i += 2) {
        if (values[i] < values[i + 1]) {
            smaller.push_back(i);
            maxima.push_back(i + 1);
        } else {
            smaller.push_back(i + 1);
            maxima.push_back(i);
        }
        larger.push_back(values[maxima.back()]);
    }
    // Sorting indices preserves each maximum's original pair, including duplicates.
    sortedPairs = this->sortVectorIndices(larger);
    for (unsigned int i = 0; i < sortedPairs.size(); i++) {
        chain.push_back(maxima[sortedPairs[i]]);
        pending.push_back(smaller[sortedPairs[i]]);
        partners.push_back(i + 1);
    }
    if (values.size() % 2 != 0) {
        pending.push_back(values.size() - 1);
    }
    // The first minimum already belongs before the first maximum: no comparison.
    chain.insert(chain.begin(), pending[0]);
    order = this->buildJacobsthalOrderVector(pending.size());
    for (std::size_t i = 1; i < order.size(); i++) {
        unsigned int index = order[i];
        unsigned int high = index < partners.size() ? partners[index] : chain.size();
        unsigned int position = this->binaryInsertVector(chain, values, pending[index], high);

        // Inserting shifts the positions of the paired maxima to its right.
        for (std::size_t j = 0; j < partners.size(); j++) {
            if (partners[j] >= position) {
                partners[j]++;
            }
        }
    }
    return chain;
}

std::deque<unsigned int> PmergeMe::sortDequeIndices(const std::deque<int>& values) const {
    std::deque<int> larger;
    std::deque<unsigned int> smaller;
    std::deque<unsigned int> maxima;
    std::deque<unsigned int> sortedPairs;
    std::deque<unsigned int> chain;
    std::deque<unsigned int> pending;
    std::deque<unsigned int> partners;
    std::deque<unsigned int> order;

    if (values.size() < 2) {
        if (!values.empty()) {
            chain.push_back(0);
        }
        return chain;
    }
    for (unsigned int i = 0; i + 1 < values.size(); i += 2) {
        if (values[i] < values[i + 1]) {
            smaller.push_back(i);
            maxima.push_back(i + 1);
        } else {
            smaller.push_back(i + 1);
            maxima.push_back(i);
        }
        larger.push_back(values[maxima.back()]);
    }
    // Reorder both members of every pair after the recursive sort.
    sortedPairs = this->sortDequeIndices(larger);
    for (unsigned int i = 0; i < sortedPairs.size(); i++) {
        chain.push_back(maxima[sortedPairs[i]]);
        pending.push_back(smaller[sortedPairs[i]]);
        partners.push_back(i + 1);
    }
    if (values.size() % 2 != 0) {
        pending.push_back(values.size() - 1);
    }
    chain.insert(chain.begin(), pending[0]);
    order = this->buildJacobsthalOrderDeque(pending.size());
    for (std::size_t i = 1; i < order.size(); i++) {
        unsigned int index = order[i];
        unsigned int high = index < partners.size() ? partners[index] : chain.size();
        unsigned int position = this->binaryInsertDeque(chain, values, pending[index], high);

        for (std::size_t j = 0; j < partners.size(); j++) {
            if (partners[j] >= position) {
                partners[j]++;
            }
        }
    }
    return chain;
}

std::vector<int> PmergeMe::mergeInsertSortVector(const std::vector<int>& values) const {
    std::vector<unsigned int> indices = this->sortVectorIndices(values);
    std::vector<int> sorted;

    sorted.reserve(values.size());
    for (std::size_t i = 0; i < indices.size(); i++) {
        sorted.push_back(values[indices[i]]);
    }
    return sorted;
}

std::deque<int> PmergeMe::mergeInsertSortDeque(const std::deque<int>& values) const {
    std::deque<unsigned int> indices = this->sortDequeIndices(values);
    std::deque<int> sorted;

    for (std::size_t i = 0; i < indices.size(); i++) {
        sorted.push_back(values[indices[i]]);
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
