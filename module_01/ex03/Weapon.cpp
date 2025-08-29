#include "Weapon.hpp"
#include <string>

Weapon::Weapon() {}

Weapon::Weapon(const std::string& arg)
: type(arg) {}

  //() is used when the object does not previously exist, 
  //= is used when the object exists
  Weapon::Weapon(const Weapon& other)
: type(other.type) {}
Weapon& Weapon::operator=(const Weapon& other) {
    if (this != &other) {
        type     = other.type;
    }
    return *this; //this is a pointer to the object
}

Weapon::~Weapon() {}

void Weapon::setType(const std::string& arg)
{
	type = arg;
}
 
const std::string& Weapon::getType() const
{
	return (type);
}