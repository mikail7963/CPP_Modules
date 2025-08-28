#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat Construction called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "Copy Construction called" << std::endl;
	this->type = copy.type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destruction called." << std::endl;
	
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{	
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "miyav" << std::endl;
}
