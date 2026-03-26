#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "----- construction -----" << std::endl;
    FragTrap a("Alpha");
    FragTrap b("Beta");

    std::cout << std::endl;
    std::cout << "----- basic actions -----" << std::endl;
    a.attack("Beta");
    b.takeDamage(30);
    b.beRepaired(10);
    a.highFivesGuys();
    b.highFivesGuys();

    std::cout << std::endl;
    std::cout << "----- copy constructor -----" << std::endl;
    FragTrap c(a);
    c.attack("training dummy");
    c.highFivesGuys();

    std::cout << std::endl;
    std::cout << "----- copy assignment -----" << std::endl;
    FragTrap d;
    d = b;
    d.attack("Alpha");
    d.highFivesGuys();

    std::cout << std::endl;
    std::cout << "----- no energy test -----" << std::endl;
    FragTrap e("EnergyBoy");
    for (int i = 0; i < 100; ++i)
        e.attack("wall");
    e.attack("one more time");
    e.beRepaired(1);
    e.highFivesGuys();

    std::cout << std::endl;
    std::cout << "----- KO test -----" << std::endl;
    FragTrap f("Fragile");
    f.takeDamage(200);
    f.attack("nobody");
    f.beRepaired(10);
    f.highFivesGuys();

    std::cout << std::endl;
    std::cout << "----- end of main -----" << std::endl;
    return 0;
}