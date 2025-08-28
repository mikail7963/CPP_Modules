#pragma once
#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal& operator=(const WrongAnimal& copy);

	void makeSound() const;

	std::string getType() const;
	void setType(const std::string str);

};
