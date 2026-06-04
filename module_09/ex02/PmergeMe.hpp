#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <string>
#include <vector>

class PmergeMe {
private:
    std::vector<int> sortedVector;
    std::deque<int>  sortedDeque;
    double           vectorTime;
    double           dequeTime;

    // ------------------ Helpers ------------------

    int parsePositiveInteger(const std::string& value) const;
    void printSequence(char** argv, int argc) const;
    void printVector(const std::vector<int>& values) const;

    std::vector<int> buildVector(int argc, char** argv) const;
    std::deque<int>  buildDeque(int argc, char** argv) const;

    std::vector<unsigned int> buildJacobsthalOrderVector(unsigned int size) const;
    std::deque<unsigned int>  buildJacobsthalOrderDeque(unsigned int size) const;

    void binaryInsertVector(std::vector<int>& values, int number) const;
    void binaryInsertDeque(std::deque<int>& values, int number) const;

    std::vector<int> mergeInsertSortVector(const std::vector<int>& values) const;
    std::deque<int>  mergeInsertSortDeque(const std::deque<int>& values) const;

public:
    // ------------------ OCF ------------------

    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    // ------------------ Methods ------------------

    void run(int argc, char** argv);
};

#endif
