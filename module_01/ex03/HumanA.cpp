#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& na, Weapon& wea)
: weapon(wea),
  name(na) {}

  //() is used when the object does not previously exist, 
  //= is used when the object exists
  HumanA::HumanA(const HumanA& other)
: weapon(other.weapon),
  name(other.name)
 {}
HumanA& HumanA::operator=(const HumanA& other) {
    if (this != &other) {
        name      = other.name;
    }
    return *this; //this is a pointer to the object
}

HumanA::~HumanA() {}

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}
