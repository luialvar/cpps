#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
private:
    // ------------------ OCF ------------------

    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

public:
    // ------------------ Methods ------------------

    static void convert(const std::string& literal);
};

#endif
