#pragma once
#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal &copy);
	virtual ~Animal();
	Animal& operator=(const Animal& copy);

	virtual void makeSound() const = 0;

	std::string getType() const;
	void setType(const std::string str);
};
