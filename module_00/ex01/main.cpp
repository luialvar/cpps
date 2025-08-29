#include <iostream>
#include <string>
#include <sstream>
#include <cctype>     // std::isspace, std::toupper
#include "PhoneBook.hpp"
#include "Contact.hpp"

// --- util: read a non-empty line (not just spaces). Returns false on EOF.
static bool readLineNonEmpty(const std::string& prompt, std::string& out) {
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, out)) {
            std::cout << "\nEOF detected. Exiting.\n";
            return false;
        }
        bool hasNonSpace = false;
        for (std::string::size_type i = 0; i < out.size(); ++i) {
            if (!std::isspace(static_cast<unsigned char>(out[i]))) {
                hasNonSpace = true;
                break;
            }
        }
        if (hasNonSpace) return true;
        std::cout << "Field cannot be empty. Please type something.\n";
    }
}

static std::string toUpperCopy(const std::string& s) {
    std::string resultado;

    std::string::size_type j = 0;
    while (j < s.size()) {
        char ch = s[j];
        if (ch >= 'a' && ch <= 'z') {
            unsigned char uc = static_cast<unsigned char>(ch);
            resultado += static_cast<char>(std::toupper(uc));
        } else {
            resultado += ch;
        }
        ++j;
    }
    return resultado;
}


static bool parseIndex(const std::string& s, int& out) {
    std::string::size_type n = s.size();
    std::string::size_type i = 0;

    while (i < n && std::isspace(static_cast<unsigned char>(s[i]))) i++;
    if (i == n) return false;

    std::string::size_type j = n;
    while (j > i && std::isspace(static_cast<unsigned char>(s[j - 1]))) j--;

    int val = 0;
    std::string::size_type k = i;
    while (k < j) {
        unsigned char ch = static_cast<unsigned char>(s[k]);
        if (!std::isdigit(ch)) return false;
        val = val * 10 + (s[k] - '0');
        k++;
    }
    out = val;
    return true;
}

// --- action: ADD
static void doAdd(PhoneBook& pb) {
    std::string first, last, nick, phone, secret;

    // Although PhoneBook::addContact validates isEmpty(), we still ask for non-empty here for UX.
    if (!readLineNonEmpty("First name: ", first))  return;
    if (!readLineNonEmpty("Last name: ", last))    return;
    if (!readLineNonEmpty("Nickname: ", nick))     return;
    if (!readLineNonEmpty("Phone number: ", phone))return;
    if (!readLineNonEmpty("Darkest secret: ", secret)) return;

    Contact c;
    c.setFirstName(first);
    c.setLastName(last);
    c.setNickname(nick);
    c.setPhoneNumber(phone);
    c.setDarkestSecret(secret);

    pb.addContact(c);
    std::cout << "Contact processed.\n"; //if not, contact is ereased
}

// --- action: SEARCH
static void doSearch(PhoneBook& pb) {
    if (pb.size() == 0) {
        std::cout << "PhoneBook is empty.\n";
        return;
    }
    pb.printTable();

    std::cout << "Index to display: ";
    std::string line;
    if (!std::getline(std::cin, line)) {
        std::cout << "\nEOF detected. Exiting.\n";
        return;
    }

    int idx = -1;
    if (!parseIndex(line, idx)) {
        std::cout << "Invalid index format.\n";
        return;
    }

    const Contact* c = pb.getContactByIndex(idx);
    if (!c) {
        std::cout << "Invalid index or empty slot.\n";
        return;
    }

    std::cout << "First name: "     << c->getFirstName()   << '\n'
              << "Last name: "      << c->getLastName()    << '\n'
              << "Nickname: "       << c->getNickname()    << '\n'
              << "Phone number: "   << c->getPhoneNumber() << '\n'
              << "Darkest secret: " << c->getDarkestSecret()<< '\n';
}

int main() {
    PhoneBook pb;
    std::string cmd;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): "; //you could just cin >> but that only reads until space
        if (!std::getline(std::cin, cmd)) {
            std::cout << "\nEOF detected. Exiting.\n";
            break;
        }

        std::string upper = toUpperCopy(cmd);
        if (upper == "ADD") {
            doAdd(pb);
        } else if (upper == "SEARCH") {
            doSearch(pb);
        } else if (upper == "EXIT") {
            break;
        } else {
            // everything else is ignored according to the exercise
        }
    }
    return 0;
}
