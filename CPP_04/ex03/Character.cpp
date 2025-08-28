#include "Character.hpp"

Character::Character(std::string str)
{
	this->name = str;
	for (size_t i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
	}
}

Character::Character(const Character &copy)
{
    this->name = copy.name;
    for (size_t i = 0; i < 4; i++)
    {
        if (copy.inventory[i])
            this->inventory[i] = copy.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& copy)
{
	if (this != &copy)
	{
		for (size_t i = 0; i < 4; i++)
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		for (size_t i = 0; i < 4; i++)
		{
			if (copy.inventory[i])
				this->inventory[i] = copy.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
		this->name = copy.name;
	}
	return *this;
}



Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		delete inventory[i];
		this->inventory[i] = NULL;
	}
	
}

std::string const& Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->inventory[idx] = NULL;
}

void Character:: use(int idx, ICharacter& target)
{
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
}

