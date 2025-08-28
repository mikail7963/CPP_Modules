#include "Zombie.hpp"

int main()
{
    Zombie* heapZombie = newZombie("Foo");
    heapZombie->announce();
    randomChump("Bob");
    Zombie stackZombie("Charlie");
    stackZombie.announce();
    delete heapZombie;
    return 0;
}
