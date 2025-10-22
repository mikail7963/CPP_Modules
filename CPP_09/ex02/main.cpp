#include "PmergeMe.hpp"

void checkArgument(std::string arg)
{
	std::stringstream ss;
	long value;
	int i = 0;
	int argLen;
	int len;

	argLen = arg.length();
	while (i < argLen)
	{
		ss.clear();
		ss.str("");
		len = 0;
		while (i < argLen && arg[i] != ' ')
		{
			if (arg.c_str()[i] && arg[i] != ' ' && !(arg[i] >= '0' &&  arg[i] <= '9'))
			{
				std::cout << "Error " << std::endl;
				exit(1);
			}
			ss << arg[i];
			i++;
			len++;
		}
		if (len > 10)
		{
			std::cout << "Error" << std::endl;
			exit(1);
		}
		ss >> value;
		if (value < 0 || value > 2147483647)
		{
			std::cout << "Error" << std::endl;
			exit(1);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == 0)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	checkArgument(argv[1]);
	PmergeMe Merge;
	std::string arg = argv[1];
	Merge.AddVector(arg);
	
}
