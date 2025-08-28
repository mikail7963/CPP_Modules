#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string	_name;
	const int		_requiredExecute;
	const int		_requiredSign;
	bool			_isSigned;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string name);
	PresidentialPardonForm(PresidentialPardonForm &cpy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &cpy);
	~PresidentialPardonForm();
	void execute(Bureaucrat const & executor) const;
	void beSigned(Bureaucrat& bureaucrat);
	int getRequiredSign() const;
	int getRequiredExecute() const;
};
