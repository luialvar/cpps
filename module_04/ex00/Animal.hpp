#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
protected:
    std::string type;

public:
    // ------------------ OCF ------------------

    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    // ------------------ Methods ------------------

    const std::string& getType() const;
    virtual void makeSound() const;
};

#endif
