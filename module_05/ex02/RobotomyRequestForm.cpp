#include "RobotomyRequestForm.hpp"
#include <cstdlib>

// ------------------ OCF ------------------

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", 72, 45), target("Default") {
    std::cout << "RobotomyRequestForm default-constructed\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45), target(target) {
    std::cout << "RobotomyRequestForm constructed\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {
    std::cout << "RobotomyRequestForm copy-constructed\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    std::cout << "RobotomyRequestForm copy-assigned\n";
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destroyed\n";
}

// ------------------ Getters ------------------

const std::string& RobotomyRequestForm::getTarget() const {
    return this->target;
}

// ------------------ Methods ------------------

void RobotomyRequestForm::executeAction() const {
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2) {
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << this->target << std::endl;
    }
}
