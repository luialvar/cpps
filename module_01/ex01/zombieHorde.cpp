#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return 0;

    Zombie* horde = new Zombie[N];
    Zombie model(name);
    for (int i = 0; i < N; ++i) {
        horde[i] = model;
    }
    return horde;
}
