#include "ScalarConverter.hpp"
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

// ------------------ OCF ------------------

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {
}

// ------------------ Helpers ------------------

static bool isDigit(char c) {
    return std::isdigit(static_cast<unsigned char>(c));
}

static bool isSign(char c) {
    return c == '+' || c == '-';
}

static bool isNan(double value) {
    return value != value;
}

static bool isInf(double value) {
    return value == std::numeric_limits<double>::infinity()
        || value == -std::numeric_limits<double>::infinity();
}

static bool hasNoFraction(double value) {
    double integerPart;

    return std::modf(value, &integerPart) == 0.0;
}

static bool isQuotedCharLiteral(const std::string& literal) {
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

static bool isCharLiteral(const std::string& literal) {
    return isQuotedCharLiteral(literal)
        || (literal.length() == 1 && !isDigit(literal[0]));
}

static bool isIntLiteral(const std::string& literal) {
    std::size_t i = 0;

    if (literal.empty()) {
        return false;
    }
    if (isSign(literal[i])) {
        i++;
    }
    if (i == literal.length()) {
        return false;
    }
    while (i < literal.length()) {
        if (!isDigit(literal[i])) {
            return false;
        }
        i++;
    }
    return true;
}

static bool isDecimalBody(const std::string& literal) {
    std::size_t i = 0;
    bool        hasDot = false;
    bool        hasDigit = false;

    if (literal.empty()) {
        return false;
    }
    if (isSign(literal[i])) {
        i++;
    }
    while (i < literal.length()) {
        if (literal[i] == '.') {
            if (hasDot) {
                return false;
            }
            hasDot = true;
        } else if (isDigit(literal[i])) {
            hasDigit = true;
        } else {
            return false;
        }
        i++;
    }
    return hasDot && hasDigit;
}

static bool isFloatPseudoLiteral(const std::string& literal) {
    return literal == "nanf" || literal == "+inff" || literal == "-inff";
}

static bool isDoublePseudoLiteral(const std::string& literal) {
    return literal == "nan" || literal == "+inf" || literal == "-inf";
}

static bool isFloatLiteral(const std::string& literal) {
    if (isFloatPseudoLiteral(literal)) {
        return true;
    }
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f') {
        return false;
    }
    return isDecimalBody(literal.substr(0, literal.length() - 1));
}

static bool isDoubleLiteral(const std::string& literal) {
    return isDoublePseudoLiteral(literal) || isDecimalBody(literal);
}

static double pseudoLiteralToDouble(const std::string& literal) {
    if (literal == "nan" || literal == "nanf") {
        return std::numeric_limits<double>::quiet_NaN();
    }
    if (literal == "+inf" || literal == "+inff") {
        return std::numeric_limits<double>::infinity();
    }
    return -std::numeric_limits<double>::infinity();
}

static bool parseLiteral(const std::string& literal, double& value) {
    std::string number;

    if (isCharLiteral(literal)) {
        if (isQuotedCharLiteral(literal)) {
            value = static_cast<double>(literal[1]);
        } else {
            value = static_cast<double>(literal[0]);
        }
        return true;
    }
    if (isFloatPseudoLiteral(literal) || isDoublePseudoLiteral(literal)) {
        value = pseudoLiteralToDouble(literal);
        return true;
    }
    if (isIntLiteral(literal) || isDoubleLiteral(literal) || isFloatLiteral(literal)) {
        number = literal;
        if (isFloatLiteral(literal) && !isFloatPseudoLiteral(literal)) {
            number = literal.substr(0, literal.length() - 1);
        }
        errno = 0;
        value = std::strtod(number.c_str(), NULL);
        return !(errno == ERANGE && isInf(value));
    }
    return false;
}

static void printImpossibleConversions() {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

static void printChar(double value) {
    char c;

    if (isNan(value) || isInf(value) || value < 0 || value > CHAR_MAX) {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    c = static_cast<char>(value);
    if (!std::isprint(static_cast<unsigned char>(c))) {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }
    std::cout << "char: '" << c << "'" << std::endl;
}

static void printInt(double value) {
    if (isNan(value) || isInf(value)
        || value < static_cast<double>(INT_MIN)
        || value > static_cast<double>(INT_MAX)) {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloatNumber(float value) {
    std::ios::fmtflags flags = std::cout.flags();
    std::streamsize    precision = std::cout.precision();

    if (hasNoFraction(static_cast<double>(value))) {
        std::cout << std::fixed << std::setprecision(1) << value;
    } else {
        std::cout.unsetf(std::ios::floatfield);
        std::cout << std::setprecision(7) << value;
    }
    std::cout.flags(flags);
    std::cout.precision(precision);
}

static void printDoubleNumber(double value) {
    std::ios::fmtflags flags = std::cout.flags();
    std::streamsize    precision = std::cout.precision();

    if (hasNoFraction(value)) {
        std::cout << std::fixed << std::setprecision(1) << value;
    } else {
        std::cout.unsetf(std::ios::floatfield);
        std::cout << std::setprecision(15) << value;
    }
    std::cout.flags(flags);
    std::cout.precision(precision);
}

static void printFloat(double value) {
    if (isNan(value)) {
        std::cout << "float: nanf" << std::endl;
        return;
    }
    if (value == std::numeric_limits<double>::infinity()) {
        std::cout << "float: +inff" << std::endl;
        return;
    }
    if (value == -std::numeric_limits<double>::infinity()) {
        std::cout << "float: -inff" << std::endl;
        return;
    }
    if (value > static_cast<double>(std::numeric_limits<float>::max())
        || value < -static_cast<double>(std::numeric_limits<float>::max())) {
        std::cout << "float: impossible" << std::endl;
        return;
    }
    std::cout << "float: ";
    printFloatNumber(static_cast<float>(value));
    std::cout << "f" << std::endl;
}

static void printDouble(double value) {
    if (isNan(value)) {
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (value == std::numeric_limits<double>::infinity()) {
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (value == -std::numeric_limits<double>::infinity()) {
        std::cout << "double: -inf" << std::endl;
        return;
    }
    std::cout << "double: ";
    printDoubleNumber(value);
    std::cout << std::endl;
}

// ------------------ Methods ------------------

void ScalarConverter::convert(const std::string& literal) {
    double value;

    if (!parseLiteral(literal, value)) {
        printImpossibleConversions();
        return;
    }
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
