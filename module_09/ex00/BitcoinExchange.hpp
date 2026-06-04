#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, double> rates;

    // ------------------ Helpers ------------------

    void loadDatabase(const std::string& filename);
    void processInput(const std::string& filename) const;
    void processLine(const std::string& line) const;
    bool getRateForDate(const std::string& date, double& rate) const;

public:
    // ------------------ OCF ------------------

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    // ------------------ Methods ------------------

    void run(const std::string& inputFile);
};

#endif
