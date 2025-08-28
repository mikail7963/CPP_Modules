#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string	_name;
	const int		_requiredExecute;
	const int		_requiredSign;
	bool			_isSigned;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string name);
	ShrubberyCreationForm(ShrubberyCreationForm &cpy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &cpy);
	~ShrubberyCreationForm();
	void execute(Bureaucrat const & executor) const;
	void beSigned(Bureaucrat& bureaucrat);
	int getRequiredExecute() const;
	int getRequiredSign() const;
};
