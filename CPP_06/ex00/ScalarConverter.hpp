#pragma once 
#include <string>
#include <iostream>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& cpy);
	ScalarConverter& operator=(ScalarConverter &cpy);
	~ScalarConverter();
public:
	static void convert(const std::string& literal);
};
