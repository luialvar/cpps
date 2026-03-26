#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "----- subject test -----" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << std::endl;
    std::cout << "----- wrong test -----" << std::endl;
    const WrongAnimal* wrong = new WrongCat();

    std::cout << wrong->getType() << std::endl;
    wrong->makeSound();

    delete wrong;

    std::cout << std::endl;
    std::cout << "----- stack test -----" << std::endl;
    Dog dog;
    Cat cat;
    Animal animal;

    dog.makeSound();
    cat.makeSound();
    animal.makeSound();

    std::cout << std::endl;
    std::cout << "----- copy test -----" << std::endl;
    Dog a;
    Dog b(a);
    Cat c;
    c = cat;

    b.makeSound();
    c.makeSound();

    return 0;
}
