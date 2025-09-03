#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(10);
	vec.push_back(15);
	vec.push_back(20);
	try
	{
		std::cout <<  *easyfind(vec,20) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::list<int> lis;
	lis.push_back(2);
	lis.push_back(4);
	lis.push_back(6);
	lis.push_back(8);
	lis.push_back(10);
	try
	{
		std::cout << *easyfind(lis, 8) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';	
	}
	try
	{
		std::cout << *easyfind(lis, 999) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
