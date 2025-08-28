#pragma once
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string& Name);
	FragTrap(const FragTrap &copy);
	~FragTrap();
	FragTrap& operator=(const FragTrap& copy);

	void highFivesGuys(void);
};
