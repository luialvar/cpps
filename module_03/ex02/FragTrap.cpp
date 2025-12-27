#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
    hitPoints = 100; energyPoints = 100; attackDamage = 30;
    std::cout << "FragTrap default-constructed\n";
}

FragTrap::FragTrap(const std::string& n) : ClapTrap(n) {
    hitPoints = 100; energyPoints = 100; attackDamage = 30;
    std::cout << "FragTrap named-constructed: " << name << "\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy-constructed\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap copy-assigned\n";
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destroyed\n";
}

void FragTrap::attack(const std::string& target) {
    if (hitPoints <= 0) { std::cout << "FragTrap " << name << " is KO\n"; return; }
    if (energyPoints <= 0) { std::cout << "FragTrap " << name << " has no energy\n"; return; }
    --energyPoints;
    std::cout << "FragTrap " << name << " blasts " << target
              << " for " << attackDamage << " damage!\n";
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " requests high fives! ✋\n";
}

//una cosa que tengo que hacer para