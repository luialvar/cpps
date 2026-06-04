#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

static void testCreatedForm(const std::string& name, const std::string& target, Bureaucrat& bureaucrat) {
    Intern intern;
    AForm* form;

    form = intern.makeForm(name, target);
    if (form) {
        std::cout << *form << std::endl;
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    }
}

static void testUnknownForm() {
    Intern intern;
    AForm* form;

    form = intern.makeForm("coffee request", "Office");
    delete form;
}

static void testLowGradeExecution() {
    Intern     intern;
    Bureaucrat signer("Signer", 1);
    Bureaucrat tiredWorker("Tired Worker", 100);
    AForm*     form;

    form = intern.makeForm("robotomy request", "Marvin");
    if (form) {
        signer.signForm(*form);
        tiredWorker.executeForm(*form);
        delete form;
    }
}

int main() {
    std::srand(std::time(NULL));
    Bureaucrat gardener("Gardener", 100);
    Bureaucrat surgeon("Surgeon", 40);
    Bureaucrat president("President", 1);

    testCreatedForm("shrubbery creation", "garden", gardener);
    testCreatedForm("robotomy request", "Bender", surgeon);
    testCreatedForm("presidential pardon", "Arthur Dent", president);
    testUnknownForm();
    testLowGradeExecution();
    return 0;
}
