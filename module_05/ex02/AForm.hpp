#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool              isSigned;
    const int         gradeToSign;
    const int         gradeToExecute;

protected:
    virtual void executeAction() const = 0;

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

    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    // ------------------ OCF ------------------

    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // ------------------ Getters ------------------

    const std::string& getName() const;
    bool               getIsSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;

    // ------------------ Methods ------------------

    void beSigned(const Bureaucrat& bureaucrat);
    void execute(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
