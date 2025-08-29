#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>


class Zombie {
private:
	std::string name;

public:
	Zombie();
    Zombie(const std::string& name);
	Zombie(const Zombie& other);            // OCF, to create and copy
    Zombie& operator=(const Zombie& other); // OCF, to copy to one that already exits
    ~Zombie(); //it will be called by its own

	void announce( void ) const;
};
	Zombie* newZombie( std::string name );
	void randomChump( std::string name );\
	Zombie* zombieHorde(int N, std::string name);

#endif
