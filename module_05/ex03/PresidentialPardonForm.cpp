#include "PresidentialPardonForm.hpp"

// ------------------ OCF ------------------

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon Form", 25, 5), target("Default") {
    std::cout << "PresidentialPardonForm default-constructed\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon Form", 25, 5), target(target) {
    std::cout << "PresidentialPardonForm constructed\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), target(other.target) {
    std::cout << "PresidentialPardonForm copy-constructed\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    std::cout << "PresidentialPardonForm copy-assigned\n";
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destroyed\n";
}

// ------------------ Getters ------------------

const std::string& PresidentialPardonForm::getTarget() const {
    return this->target;
}

// ------------------ Methods ------------------

void PresidentialPardonForm::executeAction() const {
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
