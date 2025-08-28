#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &cpy) 
{
	(void)cpy;
}

Intern& Intern::operator=(const Intern& cpy) 
{
	(void)cpy;
	return *this;
}

Intern::~Intern() {}


AForm *FormPardon(std::string target)
{
	AForm *form = new PresidentialPardonForm(target);
	return (form);
}

AForm *FormRobot(std::string target)
{
	AForm *form = new RobotomyRequestForm(target);
	return (form);
}

AForm *FormShrubbery(std::string target)
{
	AForm *form = new ShrubberyCreationForm(target);
	return (form);
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	std::string forms[3] =  {"presidential pardon", "robotomy request", "shrubbery creation" };
	AForm *(*func[3])(std::string) = {&FormPardon ,&FormRobot, &FormShrubbery};
	AForm *newForm = NULL;
	
	for (int i = 0; i < 4; i++)
	{
		if (forms[i] == formName)
		{
			newForm = (*func[i])(target);
			std::cout << GREEN << "Intern creates " << YELLOW << forms[i] << RESET << std::endl;
		}
	}
	if (!newForm)
		std::cout << RED << "A form named "  << YELLOW << formName << RED <<  " could not be found." << RESET <<  std::endl;
	return newForm;
}
