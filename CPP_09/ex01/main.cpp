#include "RPN.hpp"

void checkArgument(char **argv)
{
	int i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			i++;
			if (argv[1][i] >= '0' && argv[1][i] <= '9')
			{
				std::cout << "Error" << std::endl;
				exit(1);
			}
		}
		else if (argv[1][i] == '+'|| argv[1][i] == '-' || argv[1][i] == ' '
				|| argv[1][i] == '*' || argv[1][i] == '/')
			i++;
		else
		{
			std::cout << "Error" << std::endl;
			exit(1); 
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	checkArgument(argv);
	RPN rpn;
	std::string arg = argv[1];
	if (rpn.StartCalculate(arg))
		return (1);
}
