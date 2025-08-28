#include "Brain.hpp"
#include "Dog.hpp"

Brain::Brain()
{
	std::cout << "Brain Construction called." << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy Construction called" << std::endl;
	*this->ideas = *copy.ideas;
}

Brain::~Brain()
{
	std::cout << "Brain Destruction called." << std::endl;
}

Brain& Brain::operator=(const Brain& copy)
{	
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		*this->ideas = *copy.ideas;
	}
	return *this;
}

std::string Brain::getIdea(int i) const
{
	return this->ideas[i];
}

void Brain::setIdea( int i, const std::string& str)
{
	this->ideas[i] = str;
}
