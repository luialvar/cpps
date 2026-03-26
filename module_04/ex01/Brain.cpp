#include "Brain.hpp"
#include <iostream>

// ------------------ OCF ------------------

Brain::Brain() {
    std::cout << "Brain default-constructed\n";
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy-constructed\n";
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    std::cout << "Brain copy-assigned\n";
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destroyed\n";
}

// ------------------ Methods ------------------

void Brain::setIdea(int index, const std::string& idea) {
    if (index < 0 || index >= 100) {
        return;
    }
    ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index < 0 || index >= 100) {
        return "";
    }
    return ideas[index];
}
