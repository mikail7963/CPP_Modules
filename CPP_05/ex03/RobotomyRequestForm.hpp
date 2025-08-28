#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string	_name;
	const int		_requiredExecute;
	const int		_requiredSign;
	bool			_isSigned;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string name);
	RobotomyRequestForm(RobotomyRequestForm &cpy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &cpy);
	~RobotomyRequestForm();
	void execute(Bureaucrat const & executor) const;
	int getRequiredSign() const;
	void beSigned(Bureaucrat& bureaucrat);
	int getRequiredExecute() const;

};
