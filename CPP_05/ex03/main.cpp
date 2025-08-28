#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
    AForm* forms[4];
    try
    {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 140);
        Bureaucrat charlie("Charlie", 45);

        Intern someRandomIntern;

        forms[0] = someRandomIntern.makeForm("shrubbery creation", "Garden");
        forms[1] = someRandomIntern.makeForm("robotomy request", "Bender");
        forms[2] = someRandomIntern.makeForm("presidential pardon", "Marvin");
        forms[3] = someRandomIntern.makeForm("non-existent form", "Jack");

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << charlie << std::endl;

        for (int i = 0; i < 3; ++i)
            if (forms[i])
                std::cout << *forms[i] << std::endl;

        if (forms[0]) {
            bob.signForm(*forms[0]);
            bob.executeForm(*forms[0]);
        }

        if (forms[1]) {
            alice.signForm(*forms[1]);
            charlie.executeForm(*forms[1]);
        }

        if (forms[2]) {
            alice.signForm(*forms[2]);
            alice.executeForm(*forms[2]);
        }
        
        for (int i = 0; i < 3; ++i)
            delete forms[i];
    }
    catch (const std::exception& e)
    {
        for (int i = 0; i < 3; ++i)
            delete forms[i];
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    return 0;
}
