#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

// ------------------ OCF ------------------

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation Form", 145, 137), target("Default") {
    std::cout << "ShrubberyCreationForm default-constructed\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation Form", 145, 137), target(target) {
    std::cout << "ShrubberyCreationForm constructed\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {
    std::cout << "ShrubberyCreationForm copy-constructed\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    std::cout << "ShrubberyCreationForm copy-assigned\n";
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destroyed\n";
}

// ------------------ Getters ------------------

const std::string& ShrubberyCreationForm::getTarget() const {
    return this->target;
}

// ------------------ Methods ------------------

void ShrubberyCreationForm::executeAction() const {
    std::ofstream file((this->target + "_shrubbery").c_str());

    if (!file) {
        throw std::runtime_error("could not create shrubbery file");
    }
    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      // \\\\\n";
}
