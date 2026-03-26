#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
protected:
    std::string name;
    unsigned int         hitPoints;
    unsigned int         energyPoints;
    unsigned int         attackDamage;

public:
    // OCF
    ClapTrap();
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    // Ctor con nombre (lo usa ScavTrap)
    ClapTrap(const std::string& name);

    // Acciones
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
