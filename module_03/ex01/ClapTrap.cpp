#include "ClapTrap.hpp"
#include <iostream>

// ------------------ OCF ------------------

ClapTrap::ClapTrap()
: name(""), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap default-constructed\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
: name(other.name),
  hitPoints(other.hitPoints),
  energyPoints(other.energyPoints),
  attackDamage(other.attackDamage) {
    std::cout << "ClapTrap copy-constructed from " << other.name << "\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        name         = other.name;
        hitPoints    = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap copy-assigned from " << other.name << "\n";
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << (name.empty() ? std::string("<noname>") : name)
              << " destroyed\n";
}

// --------------- Ctor con nombre ---------------

ClapTrap::ClapTrap(const std::string& n)
: name(n), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " constructed\n";
}

// ------------------ Acciones ------------------

void ClapTrap::attack(const std::string& target) {
    if (hitPoints <= 0) {
        std::cout << "ClapTrap " << name << " can’t attack (is KO)\n";
        return;
    }
    if (energyPoints <= 0) {
        std::cout << "ClapTrap " << name << " has no energy to attack\n";
        return;
    }
    --energyPoints;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints <= 0) {
        std::cout << "ClapTrap " << name << " is already KO\n";
        return;
    }
    int dmg = static_cast<int>(amount);
    if (dmg >= hitPoints) {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount
                  << " damage and is KO!\n";
    } else {
        hitPoints -= dmg;
        std::cout << "ClapTrap " << name << " takes " << amount
                  << " damage, HP now " << hitPoints << "\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints <= 0) {
        std::cout << "ClapTrap " << name << " can’t repair (is KO)\n";
        return;
    }
    if (energyPoints <= 0) {
        std::cout << "ClapTrap " << name << " has no energy to repair\n";
        return;
    }
    --energyPoints;
    hitPoints += static_cast<int>(amount);
    std::cout << "ClapTrap " << name << " repairs " << amount
              << ", HP now " << hitPoints << "\n";
}
