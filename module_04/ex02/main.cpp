#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "----- subject test -----" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    j->makeSound();
    i->makeSound();

    delete j;
    delete i;

    std::cout << std::endl;
    std::cout << "----- array test -----" << std::endl;
    const int size = 4;
    Animal* zoo[size];

    for (int idx = 0; idx < size / 2; ++idx) {
        zoo[idx] = new Dog();
    }
    for (int idx = size / 2; idx < size; ++idx) {
        zoo[idx] = new Cat();
    }
    for (int idx = 0; idx < size; ++idx) {
        delete zoo[idx];
    }

    std::cout << std::endl;
    std::cout << "----- deep copy test -----" << std::endl;
    Dog original;
    original.setIdea(0, "guard the garden");
    original.setIdea(1, "run outside");

    Dog clone(original);
    clone.setIdea(0, "sleep all day");

    std::cout << "original idea[0]: " << original.getIdea(0) << std::endl;
    std::cout << "clone idea[0]: " << clone.getIdea(0) << std::endl;

    Cat catA;
    catA.setIdea(0, "find a warm place");
    Cat catB;
    catB = catA;
    catB.setIdea(0, "scratch the sofa");

    std::cout << "catA idea[0]: " << catA.getIdea(0) << std::endl;
    std::cout << "catB idea[0]: " << catB.getIdea(0) << std::endl;

    return 0;
}
