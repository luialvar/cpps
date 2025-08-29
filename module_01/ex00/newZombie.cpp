#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	return new Zombie(name); //heap allocation, new always returns a pointer to the object
}
