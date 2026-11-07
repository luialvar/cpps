#include "RPN.hpp"
#include <climits>
#include <sstream>
#include <stdexcept>

// ------------------ Helpers ------------------

static bool isOperator(const std::string& token) {
    return token.length() == 1
        && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

static bool isNumber(const std::string& token) {
    return token.length() == 1 && token[0] >= '0' && token[0] <= '9';
}

// ------------------ OCF ------------------

RPN::RPN() : numbers() {
}

RPN::RPN(const RPN& other) : numbers(other.numbers) {
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->numbers = other.numbers;
    }
    return *this;
}

RPN::~RPN() {
}

// ------------------ Helpers ------------------

void RPN::applyOperator(char operation) {
    int right;
    int left;

    if (this->numbers.size() < 2) {
        throw std::runtime_error("invalid expression");
    }
    right = this->numbers.top();
    this->numbers.pop();
    left = this->numbers.top();
    this->numbers.pop();
    if (operation == '+') {
        if ((right > 0 && left > INT_MAX - right)
            || (right < 0 && left < INT_MIN - right)) {
            throw std::overflow_error("integer overflow");
        }
        this->numbers.push(left + right);
    } else if (operation == '-') {
        if ((right > 0 && left < INT_MIN + right)
            || (right < 0 && left > INT_MAX + right)) {
            throw std::overflow_error("integer overflow");
        }
        this->numbers.push(left - right);
    } else if (operation == '*') {
        if ((left > 0 && right > 0 && left > INT_MAX / right)
            || (left > 0 && right < 0 && right < INT_MIN / left)
            || (left < 0 && right > 0 && left < INT_MIN / right)
            || (left < 0 && right < 0 && left < INT_MAX / right)) {
            throw std::overflow_error("integer overflow");
        }
        this->numbers.push(left * right);
    } else {
        if (right == 0) {
            throw std::runtime_error("division by zero");
        }
        //-2147483648 / -1 = 2147483648
        if (left == INT_MIN && right == -1) {
            throw std::overflow_error("integer overflow");
        }
        this->numbers.push(left / right);
    }
}

// ------------------ Methods ------------------

int RPN::evaluate(const std::string& expression) {
    //std::istringstream permite leer una cadena mediante >>, 
    //igual que leerías desde std::cin, pero tomando los datos de expression
    std::istringstream stream(expression);
    std::string        token;

    //lee hasta el siguiente espacio en blanco y omite los espacios iniciales
    while (stream >> token) {
        if (isNumber(token)) {
            this->numbers.push(token[0] - '0');
        } else if (isOperator(token)) {
            this->applyOperator(token[0]);
        } else {
            throw std::runtime_error("invalid token");
        }
    }
    if (this->numbers.size() != 1) {
        throw std::runtime_error("invalid expression");
    }
    return this->numbers.top();
}
