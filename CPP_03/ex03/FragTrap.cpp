#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << GREEN << "FragTrap Default constructor called" << RESET << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
}

FragTrap::FragTrap(const std::string& Name) : ClapTrap(Name)
{
	std::cout << GREEN << "FragTrap Constructor called" << RESET << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;

}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << RED << "Fragtrap Destructor called" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_Name = copy._Name;
		this->_AttackDamage = copy._AttackDamage;
		this->_EnergyPoints = copy._EnergyPoints;
		this->_HitPoints = copy._HitPoints;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << BLUE << _Name << RESET <<  " requests a high five! ✋😄" << std::endl;
}
