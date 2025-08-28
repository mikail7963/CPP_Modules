#include "Dog.hpp"

Dog::Dog() : _brain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog Construction called." << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) , _brain(new Brain(*copy._brain))
{
	std::cout << "Dog Copy Construction called" << std::endl;
	this->type = copy.type;
}

Dog::~Dog()
{
	std::cout << "Dog Destruction called." << std::endl;
	delete this->_brain;
}


Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		delete _brain;
		_brain = new Brain(*copy._brain);
		this->type = copy.type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Hav" << std::endl;
}

const Brain* Dog::getBrain() const 
{
    return this->_brain;
}

Brain* Dog::getBrain()
{
	return this->_brain;
}