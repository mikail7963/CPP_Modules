#include "HumanA.hpp"

HumanA::~HumanA() {}

HumanA::HumanA(std::string name, Weapon& weapon): weapon(weapon)
{
	this->name = name;
}


void HumanA::attack()
{
	std::cout << this->getName() << " attacks with their " << this->weapon.GetType() <<  std::endl;
}

std::string HumanA::getName() { return this->name; }
