#include "AForm.hpp"

AForm::AForm()  : _name("default") , _isSigned(false), _requiredExecute(150), _requiredSign(150)
{

}

AForm::AForm(std::string name, int requiredExecute, int requiredSign)  : _name(name) , _isSigned(false), _requiredExecute(requiredExecute), _requiredSign(requiredSign)
{

}

AForm::AForm(AForm &cpy) : _name(cpy._name) , _isSigned(cpy._isSigned), _requiredExecute(cpy._requiredExecute), _requiredSign(cpy._requiredSign)
{

}

AForm& AForm::operator=(AForm& cpy)
{
	if (this != &cpy)
		this->_isSigned = cpy.getIsSigned();
	return *this;
}

AForm::~AForm() {}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getRequiredSign())
	{
		this->_isSigned = true;
		std::cout << bureaucrat <<  " signed " << YELLOW <<  this->getName() << RESET << std::endl;
	}
	else
		throw GradeTooLowException();
		
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << YELLOW <<  f.getName() << RESET << ", Aform sign grade " << GREEN << f.getRequiredSign() << RESET
       << ", execute grade " << GREEN << f.getRequiredExecute() << RESET
       << ", signed: " << (f.getIsSigned() ?  GREEN + (std::string)"yes" + RESET : RED + (std::string)"no" + RESET);
    return os;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

int AForm::getRequiredSign() const
{
	return this->_requiredSign;
}

int AForm::getRequiredExecute() const
{
	return this->_requiredExecute;
}

