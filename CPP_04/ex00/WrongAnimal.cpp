#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default")
{
	std::cout << "WrongAnimal Construction called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "Copy Construction called" << std::endl;
	this->type = copy.type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destruction called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::setType(const std::string str)
{
	this->type = str;
}

void WrongAnimal::makeSound() const
{
	std::cout << "aaa" << std::endl;
}
