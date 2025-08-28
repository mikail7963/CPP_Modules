#pragma once 
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* inventory[4];
    int count;

public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource &copy);
	MateriaSource& operator=(const MateriaSource& copy);
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};
