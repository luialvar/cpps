#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(const std::string& name)
: name(name){}

  //() is used when the object does not previously exist, 
  //= is used when the object exists
  Zombie::Zombie(const Zombie& other)
: name(other.name){}
Zombie& Zombie::operator=(const Zombie& other) {
    if (this != &other) {
        name     = other.name;
    }
    return *this; //this is a pointer to the object
}
Zombie::~Zombie() {
    std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}

void Zombie::announce(void) const {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}