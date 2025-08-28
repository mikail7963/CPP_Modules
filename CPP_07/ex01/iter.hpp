#pragma once
#include <cstddef>

template <typename T, typename F>
void iter(T* array, size_t length, F f)
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T, typename F>
void iter(const T* array, size_t length, F f)
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}
