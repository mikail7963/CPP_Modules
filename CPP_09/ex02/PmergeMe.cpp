#include "PmergeMe.hpp"

PmergeMe::PmergeMe()  {}
PmergeMe::~PmergeMe() {}


void	PmergeMe::AddVector(std::string &arg)
{
	int i = 0;
	int len = arg.length();
	int value;
	std::stringstream ss;

	while (i < len)
	{
		if (arg[i] == ' ')
		{
			i++;
			continue;
		}
		ss.clear();
		ss.str("");
		while (arg[i] != ' ')
		{
			ss << arg[i];
			i++;
		}
		ss >> value;
		this->VectorNum.push_back(value);
		i++;
	}
	size_t l = 0;
	while (l < VectorNum.size())
	{
		std::cout << VectorNum[l] << " ";
		l++;
	}
}
