#pragma once 
#include "ICharacter.hpp"

class Cure : public AMateria 
{
public:
	Cure();
	~Cure();
	Cure(const Cure &copy);
	Cure& operator=(const Cure& copy);

	AMateria* clone() const;
	void use(ICharacter& target);
};