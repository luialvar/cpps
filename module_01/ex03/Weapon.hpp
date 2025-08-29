#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
	std::string type;


public:
	Weapon(); //to be able to create the eight empty Weapons of PhoneBook
    Weapon(const std::string& arg);
	Weapon(const Weapon& other);            // OCF, to create and copy
    Weapon& operator=(const Weapon& other); // OCF, to copy to one that already exits
    ~Weapon(); //it will be called by its own


	void setType(const std::string& arg);
 
    const std::string& getType() const;

};

#endif