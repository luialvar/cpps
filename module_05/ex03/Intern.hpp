#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
private:
    AForm* makeShrubberyCreationForm(const std::string& target) const;
    AForm* makeRobotomyRequestForm(const std::string& target) const;
    AForm* makePresidentialPardonForm(const std::string& target) const;

public:
    // ------------------ OCF ------------------

    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    // ------------------ Methods ------------------

    AForm* makeForm(const std::string& name, const std::string& target) const;
};

#endif
