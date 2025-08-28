#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog Construction called." << std::endl;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Copy Construction called" << std::endl;
	this->type = copy.type;
}

Dog::~Dog()
{
	std::cout << "Dog Destruction called." << std::endl;
	
}


Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Hav" << std::endl;
}