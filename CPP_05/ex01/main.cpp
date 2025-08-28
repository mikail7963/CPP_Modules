#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat high("Alice", 1);
        Bureaucrat low("Bob", 150);
        Form f1("TaxForm", 50, 25);
        Form f2("SecretForm", 1, 1);
        
        std::cout << high << std::endl;
        std::cout << low << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        
        high.signForm(f2);
        
        low.signForm(f1);
        
        for (int i = 0; i < 100; ++i)
            low.incrementGrade();
        low.signForm(f1);
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        Bureaucrat  veryHigh("Harl", 200);
        Form        f3("VeryHigh", 200, 200);

    }
    catch (const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    return 0;
}
