#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cmath>

RobotomyRequestForm::RobotomyRequestForm(std::string name) 
: AForm(name, 45, 72), _name(name) , _requiredExecute(45) , _requiredSign(72)
{}

RobotomyRequestForm::RobotomyRequestForm()
: _name("RobotomyRequestForm") ,  _requiredExecute(45) , _requiredSign(72)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &cpy)
: AForm(cpy), _name(cpy._name), _requiredExecute(cpy._requiredExecute), _requiredSign(cpy._requiredSign)
{
	this->_isSigned = cpy._isSigned;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
		this->_isSigned = copy._isSigned;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw GradeTooLowException();
	if (executor.getGrade() > getRequiredExecute())
		throw GradeTooLowException();
	std::cout << "BZZZZZZZZZZZZZZZZZZ" << std::endl;
	srand(time(0));
	float random = rand()/(1.0f + 2147483647.0f) * 100;
	if (random > 50)
		std::cout << BLUE <<  executor.getName() << RESET << GREEN <<  " has been robotomized successfully!" << RESET << std::endl;
	else
		std::cout << RED <<  "Robotomy failed on " << RESET << BLUE << executor.getName() << RESET << "!" << std::endl;
}

void RobotomyRequestForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getRequiredSign())
	{
		this->_isSigned = true;
		std::cout << bureaucrat <<  " signed " << YELLOW <<  this->getName() << RESET << std::endl;
	}
	else
		throw GradeTooLowException();
		
}

int RobotomyRequestForm::getRequiredSign() const
{
	return this->_requiredSign;
}

int RobotomyRequestForm::getRequiredExecute() const
{
	return this->_requiredExecute;
}