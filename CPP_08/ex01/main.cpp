#include "Span.hpp"
#include <iostream>

int main()
{
	try
	{
		Span sp = Span(10000);

		std::vector<unsigned int> num;
		for (size_t i = 0; i < 10000; i++)
		{
			num.push_back(i);	
		}
		sp.addNumbers(num.begin(), num.end());
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
