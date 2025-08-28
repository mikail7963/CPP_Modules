#pragma once 
#include "ICharacter.hpp"

class ICharacter;
class AMateria;

class Character : public ICharacter
{
private:
	std::string name;
	AMateria* inventory[4];
public:
	Character(std::string);
	Character(const Character &copy);
	Character& operator=(const Character& copy);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

};
