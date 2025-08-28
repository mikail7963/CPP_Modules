#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool			_isSigned;
	const int		_requiredExecute;
	const int		_requiredSign;

public:
	Form();
	Form(const std::string& name, int requiredSign, int requiredExecute);
	Form(Form &cpy);
	Form& operator=(Form& cpy);
	~Form();
	void beSigned(Bureaucrat& bureaucrat);
	std::string getName() const;
	bool getIsSigned() const;
	int getRequiredSign() const;
	int getRequiredExecute() const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Grade too high!";
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Grade too low!";
		}
	};
};

std::ostream &operator<<(std::ostream &os, const Form &b);
