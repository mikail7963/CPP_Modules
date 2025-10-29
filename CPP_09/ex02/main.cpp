#include "PmergeMe.hpp"

void checkArgument(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (!(arg[j] >= '0' && arg[j] <= '9'))
            {
                std::cout << "Error" << std::endl;
                exit(1);
            }
        }
        long value = std::atol(arg.c_str());
        if (value < 0 || value > 2147483647)
        {
            std::cout << "Error" << std::endl;
            exit(1);
        }
        if (arg.length() > 10)
        {
            std::cout << "Error" << std::endl;
            exit(1);
        }
    }
}

std::string combineArguments(int argc, char **argv)
{
	std::string combinedArgs = "";
    for (int i = 1; i < argc; i++)
    {
        combinedArgs += argv[i];
        if (i < argc - 1)
            combinedArgs += " ";
    }
	return combinedArgs;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    checkArgument(argc, argv);
    std::string combinedArgs = combineArguments(argc, argv);
    PmergeMe Merge;
    Merge.AddNumbers(combinedArgs);
    Merge.shortVector();
	Merge.shortDeque();
    return 0;
}
