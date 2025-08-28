#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond("DIAMOND");
    diamond.attack("target");
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    diamond.guardGate();
    diamond.highFivesGuys(); 
    diamond.whoAmI();
    return 0;
}
