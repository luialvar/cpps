#include "Zombie.hpp"

int main() {
    Zombie* foo = newZombie("Foo");
    foo->announce();
    delete foo; // you need to be carefull, the memory if not remains
    randomChump("Bar");
    return 0;
}
