#pragma once

#include <stdint.h>

#include "Data.h"


class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& cpy);
	Serializer& operator=(Serializer &cpy);
	~Serializer();
public:
	static Data* deserialize(uintptr_t raw);
	static uintptr_t serialize(Data* ptr);
};
