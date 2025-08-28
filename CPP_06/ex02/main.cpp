#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <fstream>

Base *generate(void)
{
	Base *base;

	unsigned int random;
	std::ifstream urandom("/dev/urandom", std::ios::in | std::ios::binary);
	urandom.read(reinterpret_cast<char*>(&random), sizeof(random));
	urandom.close();
	int value = random % 3;
	if (value == 0)
	{
		base = new A();
		return (base);
	}
	else if (value == 1)
	{
		base = new B();
		return (base);
	}
	else
	{
		base = new C();
		return (base);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "A" << std::endl;
		return;
	}
	if (dynamic_cast<B *>(p))
	{
		std::cout << "B" << std::endl;
		return;
	}
	if (dynamic_cast<C *>(p))
	{
		std::cout << "C" << std::endl;
		return;
	}
	std::cout << "unknown type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	} catch(...) { }
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	} catch(...) { }
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	} catch(...) {std::cout << "unknown type" << std::endl;}

}

int main(void)
{
	Base* basePTR = generate();
	Base* base = generate();
	Base& baseREF = *base;
	identify(basePTR);
	identify(baseREF);

	delete basePTR;
	delete base;
	return 0;
}
