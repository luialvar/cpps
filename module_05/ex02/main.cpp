#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

static void testShrubbery() {
    Bureaucrat             gardener("Gardener", 100);
    ShrubberyCreationForm  shrubbery("garden");

    std::cout << shrubbery << std::endl;
    gardener.signForm(shrubbery);
    gardener.executeForm(shrubbery);
}

static void testRobotomy() {
    Bureaucrat          surgeon("Surgeon", 40);
    RobotomyRequestForm robotomy("Bender");

    surgeon.signForm(robotomy);
    surgeon.executeForm(robotomy);
}

static void testPresidentialPardon() {
    Bureaucrat              president("President", 1);
    PresidentialPardonForm  pardon("Arthur Dent");

    president.signForm(pardon);
    president.executeForm(pardon);
}

static void testUnsignedForm() {
    Bureaucrat             executor("Executor", 1);
    ShrubberyCreationForm  shrubbery("unsigned");

    executor.executeForm(shrubbery);
}

static void testLowGradeExecution() {
    Bureaucrat          signer("Signer", 1);
    Bureaucrat          tiredWorker("Tired Worker", 100);
    RobotomyRequestForm robotomy("Marvin");

    signer.signForm(robotomy);
    tiredWorker.executeForm(robotomy);
}

int main() {
    std::srand(std::time(NULL));
    testShrubbery();
    testRobotomy();
    testPresidentialPardon();
    testUnsignedForm();
    testLowGradeExecution();
    return 0;
}
