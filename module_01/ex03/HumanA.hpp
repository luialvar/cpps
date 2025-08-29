#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
	private:
		Weapon& weapon;
		std::string name;
	public:
	HumanA(const std::string& na, Weapon& wea);
	HumanA(const HumanA& other);            // OCF, to create and copy
    HumanA& operator=(const HumanA& other); // OCF, to copy to one that already exits
    ~HumanA(); //it will be called by its own
	void attack() const;

};

#endif
