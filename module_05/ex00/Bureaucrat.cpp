#include "Bureaucrat.hpp"

// ------------------ Exceptions ------------------

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "grade is too low";
}

// ------------------ OCF ------------------

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {
    std::cout << "Bureaucrat default-constructed\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
    std::cout << "Bureaucrat constructed\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
    std::cout << "Bureaucrat copy-constructed\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->grade = other.grade;
    }
    std::cout << "Bureaucrat copy-assigned\n";
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destroyed\n";
}

// ------------------ Getters ------------------

const std::string& Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

// ------------------ Methods ------------------

void Bureaucrat::incrementGrade() {
    if (this->grade <= 1) {
        throw GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade >= 150) {
        throw GradeTooLowException();
    }
    this->grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}
