#include "PmergeMe.hpp"

void checkArgument(int argc, char **argv)
{
    std::stringstream ss;
    long value;
    for (int i = 1; i < argc; i++)
    {
        ss.clear();
        ss.str("");
        std::string arg = argv[i];
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (!(arg[j] >= '0' && arg[j] <= '9'))
            {
                std::cout << "Error" << std::endl;
                exit(1);
            }
        }
        ss << arg;
        ss >> value;
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

    std::cout << "Before: ";
    Merge.printVector();
    Merge.shortVector();
	Merge.shortDeque();
    std::cout << "After:  ";
	Merge.printVector();
    std::cout << "Time to process a range of " << Merge.ElementSize
    << " elements with std::vector  : " << std::fixed << std::setprecision(5) << Merge.getVectorTime() << " us" << std::endl;

    std::cout << "Time to process a range of " << Merge.ElementSize
        << " elements with std::deque   : " << std::fixed << std::setprecision(5) << Merge.getDequeTime() << " us" << std::endl;

    return 0;
}
