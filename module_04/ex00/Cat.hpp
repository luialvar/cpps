#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
    // ------------------ OCF ------------------

    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    // ------------------ Methods ------------------

    void makeSound() const;
};

#endif
