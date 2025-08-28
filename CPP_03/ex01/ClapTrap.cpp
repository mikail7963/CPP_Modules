#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
: _Name("Default"), _HitPoints(100), _EnergyPoints(50), _AttackDamage(20)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap Destructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& Name)
{
	std::cout << GREEN << "Claptrap Constructor called" << RESET << std::endl;
	this->_Name = Name;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) 
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_Name = copy._Name;
		this->_AttackDamage = copy._AttackDamage;
		this->_EnergyPoints = copy._EnergyPoints;
		this->_HitPoints = copy._HitPoints;
	}
	return *this;
}


void ClapTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints == 0)
	{
		std::cout << RED << "No energy points left" << RESET << std::endl;
		return;
	}
	this->_EnergyPoints--;
	std::cout	<< "ClapTrap " 
				<< BLUE	<< this->_Name	<<	RESET << " attacks "
				<< RED << target 		<<  RESET << ", causing "
				<< CYAN << this->_AttackDamage << RESET << " points of damage"
				<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_HitPoints)
	{
		std::cout << "ClapTrap " << BLUE << this->_Name << RESET << " took "
		<< CYAN << this->_HitPoints << RESET <<  " points of damage." << std::endl;
		this->_HitPoints = 0;
	}
	else
	{
		this->_HitPoints -= amount;
		std::cout << "ClapTrap " << BLUE << this->_Name << RESET << " took " << CYAN << amount << RESET
		          << " points of damage. Remaining HP: " << GREEN << this->_HitPoints << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_EnergyPoints == 0)
	{
		std::cout << RED <<  "No energy points left" << RESET << std::endl;	
		return;
	}
	unsigned int healedAmount = (amount < 100 - this->_HitPoints) ? amount : (100 - this->_HitPoints);
	this->_HitPoints += healedAmount;
	this->_EnergyPoints--;

std::cout << "ClapTrap " << BLUE << this->_Name << RESET << " repaired itself for "
	          << BLUE << healedAmount << RESET << " HP. Current HP: " << GREEN << this->_HitPoints << RESET  << std::endl;}
