#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool			_isSigned;
	const int		_requiredExecute;
	const int		_requiredSign;

public:
	AForm();
	AForm(std::string name, int requiredExecute, int requiredSign);
	AForm(AForm &cpy);
	AForm& operator=(AForm& cpy);
	virtual ~AForm();
	void beSigned(Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
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

std::ostream &operator<<(std::ostream &os, const AForm &b);
