#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->count = 0;
	for (size_t i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    this->count = copy.count;
    for (size_t i = 0; i < 4; i++)
    {
        if (copy.inventory[i])
            this->inventory[i] = copy.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
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
		this->count = copy.count;
	}
	return *this;
}


MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->count < 4 && m)
		inventory[count++] = m;
}

AMateria * MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i) 
	{
		if (inventory[i] && inventory[i]->getType() == type)
			return inventory[i]->clone();
	}
	return NULL;
}
