#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
	private:
		Weapon *weapon;
		std::string name;
	public:
	HumanB();
	HumanB(const std::string& na);
	HumanB(const HumanB& other);            // OCF, to create and copy
    HumanB& operator=(const HumanB& other); // OCF, to copy to one that already exits
    ~HumanB(); //it will be called by its own
	void attack() const;
	void setWeapon(Weapon& we);

};

#endif
