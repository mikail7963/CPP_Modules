#include "Harl.hpp"

int main(int argc, char **argv)
{
	int index = 0;
	if (argc != 2)
	{
		std::cerr << "Invalid argument\nUsage: ./program LEVEL" << std::endl;
		return 1;
 	}
	Harl harl;
	std::string level = argv[1];
	if (level == "DEBUG") {index = 1;}
	else if (level == "INFO") {index = 2;}
	else if (level == "WARNING") {index = 3;}
	else if (level == "ERROR") {index = 4;}
	switch (index)
	{
		case 1:
		{
			harl.complain("DEBUG");
			break;
		}
		case 2:
		{
			harl.complain("INFO");
			break;
		}
		case 3:
		{
			harl.complain("WARNING");
			break;
		}
		case 4:
		{
			harl.complain("ERROR");
			break;
		}		
		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		}	
	}
}
