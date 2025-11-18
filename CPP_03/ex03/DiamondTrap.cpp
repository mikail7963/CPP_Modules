#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << GREEN  << "DiamondTrap Default constructor called" << RESET << std::endl;
	this->_Name = "Default";
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) 
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

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap Destructor called" <<  RESET<< std::endl;
}

DiamondTrap::DiamondTrap(const std::string Name) : ClapTrap(Name + "_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << GREEN << "DiamondTrap Constructor called" << RESET <<  std::endl;
	this->_Name = Name;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 30;
}

void	DiamondTrap::whoAmI()
{
	std::cout	<<  "My name is "  << BLUE << DiamondTrap::_Name << RESET 
				<<  " and ClapTrap name is " << GREEN << ClapTrap::_Name << RESET << std::endl;
}
