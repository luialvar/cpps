#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB() : weapon(NULL), name("") {}


HumanB::HumanB(const std::string& na) : weapon(NULL), name(na) {}

  //() is used when the object does not previously exist, 
  //= is used when the object exists
HumanB::HumanB(const HumanB& other)
: weapon(other.weapon), name(other.name) {}

HumanB& HumanB::operator=(const HumanB& other) {
    if (this != &other) {
        name   = other.name;
        weapon = other.weapon;
    }
    return *this;
}
HumanB::~HumanB() {}

void HumanB::attack() const {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& we) {
    weapon = &we;
}