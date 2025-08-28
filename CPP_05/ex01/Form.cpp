#include "Form.hpp"

Form::Form(const std::string& name, int requiredSign, int requiredExecute): _name(name) , _requiredExecute(requiredExecute),
_requiredSign(requiredSign)
{
	if (requiredExecute > 150 || requiredSign > 150)
		throw GradeTooLowException();
	else if (requiredExecute < 1 || requiredSign < 1)
		throw GradeTooHighException();
}

Form::Form()  : _name("default") , _isSigned(false), _requiredExecute(150), _requiredSign(150)
{

}

Form::Form(Form &cpy) : _name(cpy._name) , _isSigned(cpy._isSigned), _requiredExecute(cpy._requiredExecute), _requiredSign(cpy._requiredSign)
{

}

Form& Form::operator=(Form& cpy)
{
	if (this != &cpy)
		this->_isSigned = cpy.getIsSigned();
	return *this;
}

Form::~Form() {}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getRequiredSign())
	{
		this->_isSigned = true;
		std::cout << bureaucrat <<  " signed " << YELLOW <<  this->getName() << RESET << std::endl;
	}
	else
		throw GradeTooLowException();
	
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << YELLOW <<  f.getName() << RESET << ", form sign grade " << GREEN << f.getRequiredSign() << RESET
       << ", execute grade " << GREEN << f.getRequiredExecute() << RESET
       << ", signed: " << (f.getIsSigned() ?  GREEN + (std::string)"yes" + RESET : RED + (std::string)"no" + RESET);
    return os;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

int Form::getRequiredSign() const
{
	return this->_requiredSign;
}

int Form::getRequiredExecute() const
{
	return this->_requiredExecute;
}

