#pragma once 
#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>



class Span
{
private:
	std::vector<unsigned int> numbers;
	unsigned int maxSize;
	unsigned int sizeCount;
public:
	Span();
	Span(unsigned int number);
	~Span();
	void addNumber(unsigned int number);
	unsigned int shortestSpan();
	int longestSpan();
	template <typename Iter> 
	void addNumbers(Iter begin, Iter end);
};


template <typename Iter> 
void Span::addNumbers(Iter begin, Iter end)
{
	while (begin !=end)
	{
		addNumber(*begin);
		begin++;
	}
}