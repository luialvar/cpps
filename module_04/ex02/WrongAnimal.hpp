#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
protected:
    std::string type;

public:
    // ------------------ OCF ------------------

    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    virtual ~WrongAnimal();

    // ------------------ Methods ------------------

    const std::string& getType() const;
    void makeSound() const;
};

#endif
