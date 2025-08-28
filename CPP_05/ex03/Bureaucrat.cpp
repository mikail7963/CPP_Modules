#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
: _name(name) , _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat() : _name("Default") , _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) :  _name(cpy.getName())
{
	this->_grade = cpy.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
		this->_grade = copy.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "\033[31mGrade too high!\033[0m";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "\033[31mGrade too low!\033[0m";
}

void  Bureaucrat::incrementGrade()
{
	if (this->getGrade() == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void  Bureaucrat::decrementGrade()
{
	if (this->getGrade() == 150)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << BLUE << this->_name << RESET << " signed " << YELLOW << form.getName() << RESET << std::endl;
	} 
	catch (const std::exception& e) 
	{
		std::cout << BLUE << this->_name << RESET << RED <<  " couldn’t sign " << RESET << YELLOW <<  form.getName() << RESET
				<<  RED  << " because " << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	if (form.getIsSigned())
	{
		form.execute(*this);
	}
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << BLUE <<  b.getName() << RESET << ", bureaucrat grade " << GREEN << b.getGrade() << RESET;
	return os;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;	
}