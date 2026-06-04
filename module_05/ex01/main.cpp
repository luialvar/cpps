#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void testValidForm() {
    try {
        Form taxForm("Tax Form", 50, 25);
        std::cout << taxForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

static void testInvalidHighForm() {
    try {
        Form secretForm("Secret Form", 0, 25);
        std::cout << secretForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "High form grade test: " << e.what() << std::endl;
    }
}

static void testInvalidLowForm() {
    try {
        Form impossibleForm("Impossible Form", 50, 151);
        std::cout << impossibleForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Low form grade test: " << e.what() << std::endl;
    }
}

static void testSuccessfulSignature() {
    try {
        Bureaucrat boss("Boss", 10);
        Form       contract("Contract", 50, 30);

        std::cout << contract << std::endl;
        boss.signForm(contract);
        std::cout << contract << std::endl;
    } catch (std::exception& e) {
        std::cout << "Successful signature test: " << e.what() << std::endl;
    }
}

static void testFailedSignature() {
    try {
        Bureaucrat intern("Intern", 120);
        Form       permit("Permit", 50, 30);

        std::cout << permit << std::endl;
        intern.signForm(permit);
        std::cout << permit << std::endl;
    } catch (std::exception& e) {
        std::cout << "Failed signature test: " << e.what() << std::endl;
    }
}

int main() {
    testValidForm();
    testInvalidHighForm();
    testInvalidLowForm();
    testSuccessfulSignature();
    testFailedSignature();
    return 0;
}
