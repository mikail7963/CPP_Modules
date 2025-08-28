#pragma once 
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap  : public virtual FragTrap , public virtual ScavTrap
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

};


