#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    // OCF
    FragTrap();
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    // Ctor con nombre
    FragTrap(const std::string& name);

    // Acciones
    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif
