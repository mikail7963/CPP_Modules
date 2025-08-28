#include <string>
#include "Weapon.hpp"
#ifndef HUMANB_HPP
#define HUMANB_HPP

class HumanB
{
	private:
		std::string name;
		Weapon* weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon& weapon);
		void attack();
		std::string getName();
};

#endif 