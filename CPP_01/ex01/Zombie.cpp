#include "Zombie.hpp"

Zombie::Zombie() 
{
    this->name = "";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << this->GetName() << ": deleted" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->GetName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::SetName(std::string name)
{
    this->name = name;
}

const std::string Zombie::GetName()
{
    return this->name;
}