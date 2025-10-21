#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

class RPN
{
private:
	std::vector<int> stack;
public:
	RPN();
	~RPN();
	int StartCalculate(std::string &arg);
	void AddStack(std::string &arg, int i);
	
};


#endif