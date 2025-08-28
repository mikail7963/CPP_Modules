#include "Bureaucrat.hpp"

int main()
{
    try 
	{
        Bureaucrat A("Buro", 5);
        Bureaucrat B("Buro2", 1);
        A.incrementGrade();
		std::cout << A << std::endl;
        A.decrementGrade();
		std::cout << A << std::endl;
        B.incrementGrade();
		std::cout << A << std::endl;
    }
	catch (const std::exception& e) 
	{
        std::cerr << e.what() << std::endl;
    }
}
