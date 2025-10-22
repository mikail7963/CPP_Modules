#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stack>

class RPN
{
private:
	std::stack<int> stack;
public:
	RPN();
	~RPN();
	int StartCalculate(std::string &arg);
	void AddStack(std::string &arg, int i);
	
};


#endif