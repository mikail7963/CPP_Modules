#pragma once 
#include <string>
#include <iostream>

class ICharacter;

class AMateria
{
protected:
		std::string type;
public:
	AMateria();
	AMateria(std::string const& type);
	virtual ~AMateria();
	virtual AMateria* clone() const = 0;
	std::string const & getType() const;
	virtual void use(ICharacter& target);
};

