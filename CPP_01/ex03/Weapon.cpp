#include "Weapon.hpp"

Weapon::~Weapon() {}

void Weapon::setType(std::string type) { this->type = type; }

const std::string Weapon::GetType() const { return this->type; }

Weapon::Weapon(std::string name)
{
	this->setType(name);
}
