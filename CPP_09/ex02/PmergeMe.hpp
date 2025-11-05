#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>

class PmergeMe
{
private:
	std::vector<int>	VectorNum;
	double				VectorTime;
	std::deque<int>		DequeNum;
	std::vector<int> fordJohnsonSortVec(std::vector<int> array);
	std::deque<int>  fordJohnsonSortDeq(std::deque<int> array);
	double				DequeTime;
public:
	int					ElementSize;
	PmergeMe();
	PmergeMe(const PmergeMe& obj);
	PmergeMe &operator=(const PmergeMe& obj);
	~PmergeMe();
	void AddNumbers(std::string &arg);
 	void shortVector();
 	void printVector();
 	void shortDeque();
	double getVectorTime();
	double getDequeTime();
};

#endif
