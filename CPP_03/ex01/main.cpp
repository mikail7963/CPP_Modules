#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() 
{
	ClapTrap clap("CL4P-TP");
	clap.attack("enemy1");
	clap.takeDamage(4);
	clap.beRepaired(3);

	ScavTrap scav("SC4V-TP");
	scav.attack("enemy2");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();
	scav.guardGate();
	return 0;
}
