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
	this->stack.push_back(value);
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
				if (arg[i] == '+')
					result = this->stack.back() + 0;
				if (arg[i] == '-')
					result = this->stack.back() - 0;
				if (arg[i] == '*')
					result = this->stack.back() * 0;
				this->stack.clear();
				this->stack.push_back(result);
				i++;
				continue;
            }
			int b = this->stack.back();
			this->stack.pop_back();
			int a = this->stack.back();
			this->stack.pop_back();
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
			this->stack.push_back(result);
		}
		i++;
	}
	std::cout << result << std::endl;
	return (0);
}
