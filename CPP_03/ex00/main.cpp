#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Alpha");
	ClapTrap b("Beta");

	a.attack("Beta");

	b.takeDamage(3);
	b.beRepaired(5);
	b.attack("Alpha");
	
	a.takeDamage(10);
	a.attack("Beta");
	a.takeDamage(10);
	a.beRepaired(1);
	a.beRepaired(1);
	a.beRepaired(1);
	a.beRepaired(1);
	a.beRepaired(5);
	a.beRepaired(1);
	a.beRepaired(1);
	a.beRepaired(1);
	a.beRepaired(1);

	return 0;
}
