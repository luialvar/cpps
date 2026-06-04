#include "Form.hpp"
#include "Bureaucrat.hpp"

// ------------------ Exceptions ------------------

const char* Form::GradeTooHighException::what() const throw() {
    return "form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "form grade is too low";
}

// ------------------ OCF ------------------

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "Form default-constructed\n";
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
    std::cout << "Form constructed\n";
}

Form::Form(const Form& other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute) {
    std::cout << "Form copy-constructed\n";
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    std::cout << "Form copy-assigned\n";
    return *this;
}

Form::~Form() {
    std::cout << "Form destroyed\n";
}

// ------------------ Getters ------------------

const std::string& Form::getName() const {
    return this->name;
}

bool Form::getIsSigned() const {
    return this->isSigned;
}

int Form::getGradeToSign() const {
    return this->gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->gradeToExecute;
}

// ------------------ Methods ------------------

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeToSign) {
        throw GradeTooLowException();
    }
    this->isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
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
