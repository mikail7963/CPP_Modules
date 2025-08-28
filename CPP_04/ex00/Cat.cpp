#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat Construction called." << std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Copy Construction called" << std::endl;
	this->type = copy.type;
}

Cat::~Cat()
{
	std::cout << "Cat Destruction called." << std::endl;
	
}

Cat& Cat::operator=(const Cat& copy)
{	
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "miyav" << std::endl;
}
