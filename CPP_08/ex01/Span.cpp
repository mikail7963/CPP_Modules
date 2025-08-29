#include "Span.hpp"

Span::Span()
{

}

Span::Span(unsigned int N)
{
	this->maxSize = N;
	this->sizeCount = 0;
}

Span::~Span()
{

}

void Span::addNumber(unsigned int number)
{
	if (maxSize == this->numbers.size())
		throw std::runtime_error("Error");
	this->numbers.push_back(number);
	this->sizeCount++;
}


unsigned int Span::shortestSpan()
{
	unsigned int MinSpan;
	unsigned int currentSpan;
	unsigned int i = 0;

	if (this->numbers.size() < 2)
		throw std::runtime_error("Error");
    std::sort(numbers.begin(), numbers.end());
	std::vector<unsigned int>::iterator it = numbers.begin();
	MinSpan = it[this->sizeCount - 1] - it[0];
	while (i < numbers.size() - 1)
	{
		currentSpan = numbers[i + 1] - numbers[i];
		if (currentSpan < MinSpan)
			MinSpan = currentSpan;
		i++;
	}
	return (MinSpan);
}

int Span::longestSpan()
{
	if (this->numbers.size()  < 2)
		throw std::runtime_error("Error");
	std::sort(numbers.begin(), numbers.end());
    return (numbers.back() - numbers.front());
}

