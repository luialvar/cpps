#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
private:
    std::string name;
    unsigned int         hitPoints;
    unsigned int         energyPoints;
    unsigned int         attackDamage;

public:
    // Orthodox Canonical Form (OCF)
    ClapTrap();                                // ctor por defecto
    ClapTrap(const ClapTrap& other);           // ctor de copia
    ClapTrap& operator=(const ClapTrap& other);// asignación
    ~ClapTrap();                               // dtor

    // Ctor con nombre
    ClapTrap(const std::string& name);

    // Acciones
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP
