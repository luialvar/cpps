#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ------------------ Exceptions ------------------

const char* AForm::GradeTooHighException::what() const throw() {
    return "form grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "form grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "form is not signed";
}

// ------------------ OCF ------------------

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "AForm default-constructed\n";
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
    std::cout << "AForm constructed\n";
}

AForm::AForm(const AForm& other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute) {
    std::cout << "AForm copy-constructed\n";
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    std::cout << "AForm copy-assigned\n";
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destroyed\n";
}

// ------------------ Getters ------------------

const std::string& AForm::getName() const {
    return this->name;
}

bool AForm::getIsSigned() const {
    return this->isSigned;
}

int AForm::getGradeToSign() const {
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->gradeToExecute;
}

// ------------------ Methods ------------------

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeToSign) {
        throw GradeTooLowException();
    }
    this->isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!this->isSigned) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > this->gradeToExecute) {
        throw GradeTooLowException();
    }
    this->executeAction();
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << form.getName() << ", signed: ";
    if (form.getIsSigned()) {
        out << "yes";
    } else {
        out << "no";
    }
    out << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute() << ".";
    return out;
}
