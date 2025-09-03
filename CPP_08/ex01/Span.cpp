#include "Span.hpp"

Span::Span()
{

}

Span::Span(const Span &cpy)
{
	this->maxSize = cpy.maxSize;
	this->numbers = cpy.numbers;
}

Span& Span::operator=(const Span &cpy)
{
	if (this != &cpy)
	{
		this->maxSize = cpy.maxSize;
		this->numbers = cpy.numbers;
	}
	return (*this);
}

Span::Span(unsigned int N)
{
	this->maxSize = N;
}

Span::~Span()
{

}

void Span::addNumber(unsigned int number)
{
	if (maxSize == this->numbers.size())
		throw std::runtime_error("Span is full, cannot add more elements");
	this->numbers.push_back(number);
}


unsigned int Span::shortestSpan()
{
	unsigned int MinSpan;
	unsigned int currentSpan;
	unsigned int i = 0;

	if (this->numbers.size() < 2)
		throw std::runtime_error("Need at least 2 elements to calculate span");
    std::sort(numbers.begin(), numbers.end());
	MinSpan = numbers[1] - numbers[0];
	while (i < numbers.size() - 1)
	{
		currentSpan = numbers[i + 1] - numbers[i];
		if (currentSpan < MinSpan)
			MinSpan = currentSpan;
		i++;
	}
	return (MinSpan);
}

unsigned int Span::longestSpan()
{
	if (this->numbers.size()  < 2)
		throw std::runtime_error("Error");
	std::sort(numbers.begin(), numbers.end());
    return (numbers.back() - numbers.front());
}

