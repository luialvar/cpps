#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
private:
    const std::string name;
    bool              isSigned;
    const int         gradeToSign;
    const int         gradeToExecute;

public:
    // ------------------ Exceptions ------------------

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    // ------------------ OCF ------------------

    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    // ------------------ Getters ------------------

    const std::string& getName() const;
    bool               getIsSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;

    // ------------------ Methods ------------------

    void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
