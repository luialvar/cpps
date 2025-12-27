#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
    hitPoints = 100; energyPoints = 50; attackDamage = 20;
    std::cout << "ScavTrap default-constructed\n";
}

ScavTrap::ScavTrap(const std::string& n) : ClapTrap(n) {
    hitPoints = 100; energyPoints = 50; attackDamage = 20;
    std::cout << "ScavTrap named-constructed: " << name << "\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy-constructed\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap copy-assigned\n";
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destroyed\n";
}

void ScavTrap::attack(const std::string& target) {
    if (hitPoints <= 0) { std::cout << "ScavTrap " << name << " is KO\n"; return; }
    if (energyPoints <= 0) { std::cout << "ScavTrap " << name << " has no energy\n"; return; }
    --energyPoints;
    std::cout << "ScavTrap " << name << " slashes " << target
              << " for " << attackDamage << " damage!\n";
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode\n";
}
