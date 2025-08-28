#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string& Name);
	ScavTrap(const ScavTrap &copy);
	ScavTrap& operator=(const ScavTrap& copy);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate();
};
