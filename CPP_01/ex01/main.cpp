#include "Zombie.hpp"

int main()
{
	int N = 5;

	Zombie* horde = zombieHorde(N, "Bob");
    for (int i = 0; i < N; i++)
    {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }
	delete[] horde;
}
