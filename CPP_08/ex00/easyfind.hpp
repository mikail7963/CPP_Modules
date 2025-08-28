#pragma once 
#include <algorithm>
#include <string>
#include <iostream>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator iter = container.begin();
	while (iter != container.end())
	{		
		if (*iter == value)
			return (iter);
		iter++;
	}
	throw std::runtime_error("Value not found");
}
