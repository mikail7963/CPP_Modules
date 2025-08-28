#include <string>
#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	~Zombie();
	void announce( void );
	Zombie(std::string name);
	void SetName(std::string name);
	const std::string GetName();

};

Zombie* newZombie(std::string name);
void randomChump( std::string name );

