#include "ClapTrap.hpp"

int main() {
    ClapTrap a("A"), b("B");
    a.attack("B");
    b.takeDamage(3);
    b.attack("A");
    a.takeDamage(2);
    a.beRepaired(1);
    b.beRepaired(1);
    ClapTrap c(a);
    c.attack("B");
    ClapTrap d;
    d = b;
    d.attack("A");
    return 0;
}
