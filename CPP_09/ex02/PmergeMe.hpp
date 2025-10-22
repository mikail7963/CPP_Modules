#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <deque>

class PmergeMe
{
private:
	std::vector<int>	VectorNum;
	std::deque<int>		DequeNum;
public:
	PmergeMe();
	~PmergeMe();
	void AddVector(std::string &arg);
};



#endif