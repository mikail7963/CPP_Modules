#include "HumanB.hpp"

HumanB::~HumanB() {}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;	
}

std::string HumanB::getName() { return this->name; }


void HumanB::attack()
{
	if (this->weapon)
		std::cout << this->getName() << " attacks with their " << this->weapon->GetType() <<  std::endl;
	else
		std::cout << this->getName() << " has no weapon to attack with." << std::endl;
}