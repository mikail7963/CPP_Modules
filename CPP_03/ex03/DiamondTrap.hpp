#pragma once 
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap  : public virtual ScavTrap , public virtual FragTrap
{
private:
	std::string		_Name;
public:
	DiamondTrap();
	DiamondTrap(const std::string Name);
	DiamondTrap(const DiamondTrap &copy);
	~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap& copy);
	void	whoAmI();
	using ScavTrap::attack;
};
