#pragma once
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
public:
	Intern();
	Intern(const Intern &cpy);
	Intern& operator=(const Intern& cpy);
	~Intern();
	AForm *makeForm(std::string formName, std::string target);
};

