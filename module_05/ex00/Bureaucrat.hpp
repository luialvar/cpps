#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
private:
    const std::string name;
    int               grade;

public:
    // ------------------ Exceptions ------------------
    // Overrides std::exception::what().
    // Returns a message describing the error.
    // const means this function does not modify the exception object.
    // throw() means this function will not throw another exception.
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    // ------------------ OCF ------------------

    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // ------------------ Getters ------------------

    const std::string& getName() const;
    int                getGrade() const;

    // ------------------ Methods ------------------

    void incrementGrade();
    void decrementGrade();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
