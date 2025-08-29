#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
private:
    // Private behaviors (not exposed)
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    Harl();                               // OCF: default constructor
    Harl(const Harl& other);              // OCF: copy constructor
    Harl& operator=(const Harl& other);   // OCF: copy assignment
    ~Harl();                              // OCF: destructor

    // Call one of the four behaviors depending on 'level'
    // Implemented with pointers-to-member-functions (no if/else forest).
    void complain(const std::string& level);
};

#endif
