#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "----- array test -----" << std::endl;
    const int size = 6;
    Animal* zoo[size];

    for (int i = 0; i < size / 2; ++i) {
        zoo[i] = new Dog();
    }
    for (int i = size / 2; i < size; ++i) {
        zoo[i] = new Cat();
    }
    for (int i = 0; i < size; ++i) {
        delete zoo[i];
    }

    std::cout << std::endl;
    std::cout << "----- deep copy dog -----" << std::endl;
    Dog basicDog;
    basicDog.setIdea(0, "protect the house");
    basicDog.setIdea(1, "play with the ball");

    Dog copiedDog(basicDog);
    copiedDog.setIdea(0, "sleep on the sofa");

    std::cout << "basicDog idea[0]: " << basicDog.getIdea(0) << std::endl;
    std::cout << "copiedDog idea[0]: " << copiedDog.getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "----- deep copy cat -----" << std::endl;
    Cat basicCat;
    basicCat.setIdea(0, "eat fish");

    Cat assignedCat;
    assignedCat = basicCat;
    assignedCat.setIdea(0, "ignore everyone");

    std::cout << "basicCat idea[0]: " << basicCat.getIdea(0) << std::endl;
    std::cout << "assignedCat idea[0]: " << assignedCat.getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "----- base pointer test -----" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    j->makeSound();
    i->makeSound();

    delete j;
    delete i;

    return 0;
}
