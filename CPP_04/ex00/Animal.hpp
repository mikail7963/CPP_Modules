#pragma once
#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &copy);
	Animal& operator=(const Animal& copy);

	virtual void makeSound() const;

	std::string getType() const;
	void setType(const std::string str);
};
