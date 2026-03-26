#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "----- construction -----" << std::endl;
    ScavTrap a("Alpha");
    ScavTrap b("Beta");

    std::cout << std::endl;
    std::cout << "----- basic actions -----" << std::endl;
    a.attack("Beta");
    b.takeDamage(20);
    b.beRepaired(5);
    b.guardGate();

    std::cout << std::endl;
    std::cout << "----- copy constructor -----" << std::endl;
    ScavTrap c(a);
    c.attack("target dummy");
    c.guardGate();

    std::cout << std::endl;
    std::cout << "----- copy assignment -----" << std::endl;
    ScavTrap d;
    d = b;
    d.attack("Alpha");
    d.guardGate();

    std::cout << std::endl;
    std::cout << "----- no energy test -----" << std::endl;
    ScavTrap e("EnergyBoy");
    for (int i = 0; i < 50; ++i)
        e.attack("wall");
    e.attack("one more time");
    e.beRepaired(1);

    std::cout << std::endl;
    std::cout << "----- KO test -----" << std::endl;
    ScavTrap f("Fragile");
    f.takeDamage(200);
    f.attack("nobody");
    f.beRepaired(10);
    f.guardGate();

    std::cout << std::endl;
    std::cout << "----- end of main -----" << std::endl;
    return 0;
}