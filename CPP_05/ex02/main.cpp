#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 100);
        Bureaucrat charlie("Charlie", 45);

        AForm* forms[3];
        forms[0] = new ShrubberyCreationForm("garden");
        forms[1] = new RobotomyRequestForm("Bender");
        forms[2] = new PresidentialPardonForm("Marvin");

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << charlie << std::endl;

        for (int i = 0; i < 3; ++i)
            std::cout << *forms[i] << std::endl;

        bob.signForm(*forms[0]);
        bob.executeForm(*forms[0]);

        alice.signForm(*forms[1]);
        charlie.executeForm(*forms[1]);

        alice.signForm(*forms[2]);
        alice.executeForm(*forms[2]);

        for (int i = 0; i < 3; ++i)
            delete forms[i];
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
