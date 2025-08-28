#pragma once
#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class ClapTrap
{
protected:
	std::string		_Name;
	unsigned int	_HitPoints;
	unsigned int	_EnergyPoints;
	unsigned int	_AttackDamage;
public:
	ClapTrap();
	ClapTrap(const std::string& Name);
	ClapTrap(const ClapTrap &copy);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& copy);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

