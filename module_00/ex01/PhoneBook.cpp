#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>  // std::setw
#include <string>

static std::string formatField(const std::string& s) {
    if (s.size() > 10)
        return s.substr(0, 9) + ".";
    return s;
}

PhoneBook::PhoneBook() : count(0), nextIndex(0) {}

PhoneBook::PhoneBook(const PhoneBook& other)
: count(other.count), nextIndex(other.nextIndex) {
    for (int i = 0; i < 8; ++i) contacts[i] = other.contacts[i];
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
    if (this != &other) {
        count     = other.count;
        nextIndex = other.nextIndex;
        for (int i = 0; i < 8; ++i) contacts[i] = other.contacts[i];
    }
    return *this;
}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact& c) {
    // Rechaza contactos con algún campo vacío
    if (c.isEmpty()) {
        std::cout << "Error: not possible to store a contact with empty parts.\n";
        return;
    }

    contacts[nextIndex] = c;
    nextIndex = (nextIndex + 1) % 8;
    if (count < 8)
        ++count;
}


int PhoneBook::size() const {
    return count;
}

/**
 * @brief Prints a summary table of saved contacts.
 * @details Shows four right-aligned columns (width 10): index, first name, last name, nickname.
 *          Fields longer than 10 characters are truncated with the last character replaced by '.' via formatField().
 *          Reads the first `count` entries of the fixed-size `contacts` array. Performs output only and does not modify state.
 */
void PhoneBook::printTable() const {
    std::cout << std::setw(10) << "index"     << '|'
              << std::setw(10) << "first name"<< '|'
              << std::setw(10) << "last name" << '|'
              << std::setw(10) << "nickname"  << '\n';
    for (int i = 0; i < count; ++i) {
        const Contact& c = contacts[i];
        std::cout << std::setw(10) << i << '|'
                  << std::setw(10) << formatField(c.getFirstName()) << '|'
                  << std::setw(10) << formatField(c.getLastName())  << '|'
                  << std::setw(10) << formatField(c.getNickname())  << '\n';
    }
}

/**
 * @brief Returns a read-only pointer to the contact at the given zero-based index.
 * @param index Zero-based index into the logical range [0, count).
 * @return const Contact* Pointer to the contact if the index is valid and the slot is non-empty; otherwise NULL (0).
 * @note  The returned pointer remains valid as long as this PhoneBook object is alive and the slot is not overwritten.
 *        The pointed contact is const to prevent external mutation of internal state.
 */
const Contact* PhoneBook::getContactByIndex(int index) const {
    if (index < 0 || index >= count)
        return 0;
    if (contacts[index].isEmpty())
        return 0;
    return &contacts[index];
}
