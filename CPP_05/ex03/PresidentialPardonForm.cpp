#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name)  :  AForm(name, 5, 25), _name(name) , _requiredExecute(5) , 
 _requiredSign(25)  {}


PresidentialPardonForm::PresidentialPardonForm() : _name("PresidentialPardonForm") , _requiredExecute(5) , _requiredSign(25) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cpy)
: AForm(cpy), _name(cpy._name), _requiredExecute(cpy._requiredExecute), _requiredSign(cpy._requiredSign)
{
	this->_isSigned = cpy._isSigned;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
		this->_isSigned = copy._isSigned;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw GradeTooLowException();
	if (executor.getGrade() > getRequiredExecute())
		throw GradeTooLowException();
	std::cout	<< YELLOW << "You have been pardoned by Zaphod Beeblebrox, " << RESET
				<< BLUE <<  executor.getName() << RESET << std::endl;
}

void PresidentialPardonForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getRequiredSign())
	{
		this->_isSigned = true;
		std::cout << bureaucrat <<  " signed " << YELLOW <<  this->getName() << RESET << std::endl;
	}
	else
		throw GradeTooLowException();
		
}

int PresidentialPardonForm::getRequiredSign() const
{
	return this->_requiredSign;
}

int PresidentialPardonForm::getRequiredExecute() const
{
	return this->_requiredExecute;
}