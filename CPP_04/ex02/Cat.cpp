#include "Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
	this->type = "Cat";
	std::cout << "Cat Construction called." << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) , _brain(new Brain(*copy._brain))
{
	std::cout << "Cat Copy Construction called" << std::endl;
	this->type = copy.type;
}

Cat::~Cat()
{
	std::cout << "Cat Destruction called." << std::endl;
	delete this->_brain;
	
}

Cat& Cat::operator=(const Cat& copy)
{	
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		delete _brain;
		_brain = new Brain(*copy._brain);
		this->type = copy.type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "miyav" << std::endl;
}


const Brain* Cat::getBrain() const 
{
    return this->_brain;
}

Brain* Cat::getBrain()
{
	return this->_brain;
}