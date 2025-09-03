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
public:
	Span();
	Span(const Span &cpy);
	Span& operator=(const Span &cpy);
	~Span();
	Span(unsigned int number);
	void addNumber(unsigned int number);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	template <typename Iter> 
	void addNumbers(Iter begin, Iter end);
};


template <typename Iter> 
void Span::addNumbers(Iter begin, Iter end)
{
	numbers.insert(numbers.end(), begin, end);
}