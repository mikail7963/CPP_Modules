#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) 
: AForm(name, 137, 145), _name(name) , _requiredExecute(137) , _requiredSign(145)
{}


ShrubberyCreationForm::ShrubberyCreationForm() 
: _name("ShrubberyCreationForm"),  _requiredExecute(137) , _requiredSign(145)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &cpy)
: AForm(cpy), _name(cpy._name), _requiredExecute(cpy._requiredExecute), _requiredSign(cpy._requiredSign)
{
	this->_isSigned = cpy._isSigned;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
		this->_isSigned = copy._isSigned;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw GradeTooLowException();
	if (executor.getGrade() > getRequiredExecute())
		throw GradeTooLowException();
	std::string newfile = executor.getName() + "_shrubbery";
	std::ofstream outFile(newfile.c_str());
	if (!outFile)
        std::cerr << "output file can't be created" << std::endl;
	outFile <<
	"      ccee88oo\n"
	"   C8O8O8Q8PoOb o8oo\n"
	"  dOB69QO8PdUOpugoO9bD\n"
	" CgggbU8OU qOp qOdoUOdcb\n"
	"    6OuU  /p u gcoUodpP\n"
	"      \\\\//  /douUP\n"
	"        \\\\////\n"
	"         |||/\\\n"
	"         |||\\/\n"
	"         |||||\n"
	"   .....//||||\\....\n";
}


void ShrubberyCreationForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getRequiredSign())
	{
		this->_isSigned = true;
		std::cout << bureaucrat <<  " signed " << YELLOW <<  this->getName() << RESET << std::endl;
	}
	else
		throw GradeTooLowException();
}

int ShrubberyCreationForm::getRequiredSign() const
{
	return this->_requiredSign;
}

int ShrubberyCreationForm::getRequiredExecute() const
{
	return this->_requiredExecute;
}