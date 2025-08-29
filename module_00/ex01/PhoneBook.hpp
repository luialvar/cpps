#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int     count;     // number of current contacts
    int     nextIndex; // pos where to insert next contact

public:
    PhoneBook();
	PhoneBook(const PhoneBook& other);            // OCF
    PhoneBook& operator=(const PhoneBook& other); // OCF
    ~PhoneBook();

    void addContact(const Contact& c);
    int  size() const;

    void printTable() const;
    const Contact* getContactByIndex(int index) const;
};

#endif
