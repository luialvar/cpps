#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

// ------------------ OCF ------------------

Intern::Intern() {
    std::cout << "Intern default-constructed\n";
}

Intern::Intern(const Intern& other) {
    (void)other;
    std::cout << "Intern copy-constructed\n";
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    std::cout << "Intern copy-assigned\n";
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destroyed\n";
}

// ------------------ Methods ------------------

AForm* Intern::makeShrubberyCreationForm(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const {
    typedef AForm* (Intern::*FormMaker)(const std::string& target) const;

    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    FormMaker formMakers[3] = {
        &Intern::makeShrubberyCreationForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makePresidentialPardonForm
    };

    for (int i = 0; i < 3; i++) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*formMakers[i])(target);
        }
    }
    std::cout << "Intern couldn't create " << name << " because the form does not exist" << std::endl;
    return NULL;
}
