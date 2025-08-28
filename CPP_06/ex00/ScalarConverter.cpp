#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <limits>


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy) { (void)cpy; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter &copy)
{
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;
	
    if (literal == "nan" || literal == "nanf") 
	{
        std::cout << "char:   impossible" << std::endl;
        std::cout << "int:    impossible" << std::endl;
        std::cout << "float:  nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff"
     || literal == "-inf" || literal == "-inff") {
        const bool neg = !literal.empty() && literal[0] == '-';
        std::cout << "char:   impossible" << std::endl;
        std::cout << "int:    impossible" << std::endl;
        std::cout << "float:  " << (neg ? "-inff" : "+inff") << std::endl;
        std::cout << "double: " << (neg ? "-inf"  : "+inf")  << std::endl;
        return;
    }
	if (literal.length() > 1)
	{
		for (size_t i = 0; i < literal.length(); i++)
		{
			if (literal[i] != '-' && literal[i] != '+' && literal[i] != '.' && literal[i] != 'f' && literal[i] != 'F' 
				&& !std::isdigit(static_cast<unsigned char>(literal[i])))
			{
        		std::cout << "char:   impossible" << std::endl;
        		std::cout << "int:    impossible" << std::endl;
        		std::cout << "float:  impossible" << std::endl;
        		std::cout << "double: impossible"<< std::endl;
				return;
			}
		}
	}
	if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
	{
		c = literal[0];
		i = static_cast<int>(c);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
	}
	else if (literal.find('.') != std::string::npos)
	{
		if (literal[literal.size() - 1] == 'f')
		{
			f = std::atof(literal.c_str());
        	std::string num = literal.substr(0, literal.size() - 1);
        	f = static_cast<float>(std::atof(num.c_str()));
        	d = static_cast<double>(f);
        	i = static_cast<int>(f);
        	c = static_cast<char>(i);
		}
		else
		{
			char *end = 0;
			d = std::strtod(literal.c_str(), &end);
			f = static_cast<float>(d);
        	i = static_cast<int>(d);
        	c = static_cast<char>(i);
		}
	}
	else
	{
		i = std::atoi(literal.c_str());
    	c = static_cast<char>(i);
    	f = static_cast<float>(i);
    	d = static_cast<double>(i);
	}
	
	std::cout << "char:   ";
	if (i < 0 || i > 127)
    	std::cout << "impossible";
	else if (c < 32 || c == 127)
		std::cout << "Non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << std::endl;
	std::cout << "int:    " << i << std::endl;
	std::cout  << std::fixed << std::setprecision(1) << "float:  " << f  << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
