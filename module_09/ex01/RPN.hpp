#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <stack>
#include <string>

class RPN {
private:
    std::stack<int, std::list<int> > numbers;

    // ------------------ Helpers ------------------

    void applyOperator(char operation);

public:
    // ------------------ OCF ------------------

    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    // ------------------ Methods ------------------

    int evaluate(const std::string& expression);
};

#endif
