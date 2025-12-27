#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    // OCF
    ScavTrap();
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();

    // Ctor con nombre
    ScavTrap(const std::string& name);

    // Acciones
    void attack(const std::string& target);
    void guardGate();
};

#endif
