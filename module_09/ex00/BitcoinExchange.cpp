#include "BitcoinExchange.hpp"
#include <cerrno>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

// ------------------ Helpers ------------------

static std::string trim(const std::string& text) {
    std::size_t start = 0;
    std::size_t end = text.length();

    while (start < text.length()
        && (text[start] == ' ' || text[start] == '\t' || text[start] == '\r')) {
        start++;
    }
    while (end > start
        && (text[end - 1] == ' ' || text[end - 1] == '\t' || text[end - 1] == '\r')) {
        end--;
    }
    return text.substr(start, end - start);
}

static bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

static int stringToInt(const std::string& value) {
    return std::atoi(value.c_str());
}

static bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

static bool isValidDate(const std::string& date) {
    int         year;
    int         month;
    int         day;
    const int   daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    for (std::size_t i = 0; i < date.length(); i++) {
        if (i != 4 && i != 7 && !isDigit(date[i])) {
            return false;
        }
    }
    year = stringToInt(date.substr(0, 4));
    month = stringToInt(date.substr(5, 2));
    day = stringToInt(date.substr(8, 2));
    if (month < 1 || month > 12 || day < 1) {
        return false;
    }
    if (month == 2 && isLeapYear(year)) {
        return day <= 29;
    }
    return day <= daysInMonth[month - 1];
}

static bool parseDouble(const std::string& text, double& value) {
    char* end;

    errno = 0;
    value = std::strtod(text.c_str(), &end);
    if (text.empty() || *end != '\0' || errno == ERANGE || value != value) {
        return false;
    }
    return true;
}

static bool parseInputValue(const std::string& text, double& value, std::string& error) {
    if (!parseDouble(text, value)) {
        error = "bad input";
        return false;
    }
    if (value < 0) {
        error = "not a positive number";
        return false;
    }
    if (value > 1000) {
        error = "too large a number";
        return false;
    }
    return true;
}

// ------------------ OCF ------------------

BitcoinExchange::BitcoinExchange() : rates() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : rates(other.rates) {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->rates = other.rates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

// ------------------ Helpers ------------------

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    std::string   line;

    if (!file) {
        throw std::runtime_error("could not open database");
    }
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::size_t comma = line.find(',');
        std::string date;
        std::string valueText;
        double      value;

        if (comma == std::string::npos) {
            continue;
        }
        date = trim(line.substr(0, comma));
        valueText = trim(line.substr(comma + 1));
        if (isValidDate(date) && parseDouble(valueText, value)) {
            this->rates[date] = value;
        }
    }
    if (file.bad()) {
        throw std::runtime_error("could not read database");
    }
    if (this->rates.empty()) {
        throw std::runtime_error("empty database");
    }
}

void BitcoinExchange::processInput(const std::string& filename) const {
    std::ifstream file(filename.c_str());
    std::string   line;

    if (!file) {
        throw std::runtime_error("could not open file");
    }
    if (std::getline(file, line) && trim(line) != "date | value") {
        this->processLine(line);
    }
    while (std::getline(file, line)) {
        if (!trim(line).empty()) {
            this->processLine(line);
        }
    }
    if (file.bad()) {
        throw std::runtime_error("could not read file");
    }
}

void BitcoinExchange::processLine(const std::string& line) const {
    std::size_t separator = line.find('|');
    std::string date;
    std::string valueText;
    std::string error;
    double      value;
    double      rate;

    if (separator == std::string::npos) {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }
    date = trim(line.substr(0, separator));
    valueText = trim(line.substr(separator + 1));
    if (!isValidDate(date)) {
        std::cout << "Error: bad input => " << date << std::endl;
        return;
    }
    if (!parseInputValue(valueText, value, error)) {
        if (error == "bad input") {
            std::cout << "Error: bad input => " << line << std::endl;
        } else {
            std::cout << "Error: " << error << "." << std::endl;
        }
        return;
    }
    if (!this->getRateForDate(date, rate)) {
        std::cout << "Error: bad input => " << date << std::endl;
        return;
    }
    std::cout << date << " => " << valueText << " = " << value * rate << std::endl;
}

bool BitcoinExchange::getRateForDate(const std::string& date, double& rate) const {
    //if last one, returns end
    std::map<std::string, double>::const_iterator it = this->rates.upper_bound(date);

    if (it == this->rates.begin()) {
        return false;
    }
    --it;
    //it->first: la fecha.
    //it->second: el precio
    rate = it->second;
    return true;
}

// ------------------ Methods ------------------

void BitcoinExchange::run(const std::string& inputFile) {
    this->loadDatabase("data.csv");
    this->processInput(inputFile);
}
