#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
 		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return (1);
	}
	if (!argv[1][0])
	{
 		std::cerr << "Cannot be literally empty" << std::endl;
		return (1);
	}

	ScalarConverter::convert(std::string(argv[1]));
	return (0);
}
