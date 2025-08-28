#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() 
{
    ClapTrap clap("CLAPPY");
    clap.attack("target dummy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    ScavTrap scav("SCAVVY");
    scav.attack("intruder");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    FragTrap frag("FRAGGY");
    frag.attack("bad man");
    frag.takeDamage(50);
    frag.beRepaired(25);
    frag.highFivesGuys();

    return 0;
}
