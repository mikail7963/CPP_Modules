#pragma once
#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat();
	Bureaucrat(const Bureaucrat &cpy);
	Bureaucrat& operator=(const Bureaucrat &cpy);
	~Bureaucrat();

	void incrementGrade();
	void decrementGrade();
	std::string getName() const;
	int getGrade() const;
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

