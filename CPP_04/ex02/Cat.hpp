#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* _brain;
public:
	Cat();
	Cat(const Cat &copy);
	~Cat();
	Cat& operator=(const Cat& copy);

	virtual void makeSound() const;
	Brain* getBrain();
	const Brain* getBrain() const;
};
