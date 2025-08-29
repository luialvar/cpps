#include "Harl.hpp"
#include <iostream>

// () is used when the object does not previously exist,
// = is used when the object exists
Harl::Harl() {}
Harl::Harl(const Harl& other) { (void)other; }
Harl& Harl::operator=(const Harl& other) {
    if (this != &other) {
        // No state to copy (stateless class)
    }
    return *this;
}
Harl::~Harl() {}

void Harl::debug(void) {
    std::cout
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-"
           "special-ketchup burger. I really do!"
        << std::endl;
}

void Harl::info(void) {
    std::cout
        << "I cannot believe adding extra bacon costs more money. You didn’t put "
           "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
        << std::endl;
}

void Harl::warning(void) {
    std::cout
        << "I think I deserve to have some extra bacon for free. I’ve been coming "
           "for years, whereas you started working here just last month."
        << std::endl;
}

void Harl::error(void) {
    std::cout
        << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
}

void Harl::complain(const std::string& level) {
    // Pointer-to-member-function type
    typedef void (Harl::*Handler)(void);

    // Lookups aligned by index (no if/else, no switch on strings in C++98)
    static const std::string keys[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    static const Handler     fns[4]  = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < 4; ++i) {
        if (keys[i] == level) {
            (this->*fns[i])();   // call the selected member function
            return;
        }
    }
    // Optional: handle unknown input (subject doesn't force it)
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
