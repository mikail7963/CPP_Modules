#include "Animal.hpp"

Animal::Animal() : type("Default")
{
	std::cout << "Animal Construction called." << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Copy Construction called" << std::endl;
	this->type = copy.type;
}

Animal::~Animal()
{
	std::cout << "Animal Destruction called." << std::endl;
}


Animal& Animal::operator=(const Animal& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::setType(const std::string str)
{
	this->type = str;
}

void Animal::makeSound() const
{
	std::cout << "aaa" << std::endl;
}