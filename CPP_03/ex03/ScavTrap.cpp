#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << GREEN  << "ScavTrap Default constructor called" << RESET << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) 
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

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap Destructor called" <<  RESET<< std::endl;
}

ScavTrap::ScavTrap(const std::string& Name) : ClapTrap(Name)
{
	std::cout << GREEN << "ScavTrap Constructor called" << RESET <<  std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
}

void ScavTrap::guardGate()
{
	static bool mode = false;

	mode = !mode;
	if (mode)
		std::cout << YELLOW << "ScavTrap Gatekeeper mode active" << RESET << std::endl;
	else
		std::cout << YELLOW << "ScavTrap Gatekeeper mode inactive" << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints == 0)
	{
		std::cout << RED << "No energy points left" << RESET << std::endl;	
		return;
	}
	this->_EnergyPoints--;
	std::cout	<< "ScavTrap "
				<< BLUE << this->_Name << RESET << " attacks "
				<< RED << target << RESET << ", causing "
				<< CYAN << this->_AttackDamage << RESET << " points of damage"
				<< std::endl;

}
