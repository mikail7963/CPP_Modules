#include "Serializer.hpp"
#include <cstdlib>


Serializer::Serializer() {}

Serializer::Serializer(const Serializer &cpy) { (void)cpy; }

Serializer &Serializer::operator=(Serializer &copy)
{
	(void)copy;
	return *this;
}

Serializer::~Serializer() {}


Data* Serializer::deserialize(uintptr_t raw)
{
	Data* ptr = reinterpret_cast<Data*>(raw);
	return (ptr);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t res = reinterpret_cast<uintptr_t>(ptr);
	return (res);
}
