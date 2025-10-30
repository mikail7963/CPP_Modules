#include "RPN.hpp"

RPN::RPN()  {}
RPN::~RPN() {}


void RPN::AddStack(std::string &arg, int i)
{
	int value;

	std::stringstream ss;
	ss.str("");
	ss.clear();
	ss << arg[i];
	ss >> value;
	this->stack.push(value);
}

int RPN::StartCalculate(std::string &arg)
{
	int i = 0;
	int result = 1;
	while (arg[i])
	{
		if (arg[i] == ' ')
		{
			i++;
			continue;
		}
		if (arg[i] >= '0' && arg[i] <= '9')
			AddStack(arg, i);
		else
		{
			if (this->stack.size() < 2)
            {
				std::cout << "Error" << std::endl;
				return (1);
            }
			int b = this->stack.top();
			this->stack.pop();
			int a = this->stack.top();
			this->stack.pop();
			if (arg[i] == '+')
				result = a + b;
			if (arg[i] == '-')
				result = a - b;
			if (arg[i] == '*')
				result = a * b;
			if (arg[i] == '/')
			{
				if (b == 0)
                {
                    std::cout << "Error: division by zero" << std::endl;
                    return (1);
                }
				result = a / b;
			}
			this->stack.push(result);
		}
		i++;
	}
	if (this->stack.size() != 1)
	{
        std::cout << "Error: error" << std::endl;
		return (1);
	}
	std::cout << this->stack.top() << std::endl;
	return (0);
}
