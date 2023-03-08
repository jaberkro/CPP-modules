#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class AForm::GradeTooHighException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Exception: grade too high");
		}
};

class AForm::GradeTooLowException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Exception: grade too low");
		}
};

class AForm::FormNotSignedException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Exception: form not signed");
		}
};

AForm::AForm(): _name("Nameless"), _signed(0), _signGrade(150), _executeGrade(150)
{
	std::cout << "Default constructor called on AForm" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int executeGrade): _name(name), _signed(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Parametric constructor called on AForm" << std::endl;
}

AForm::AForm(const AForm &src): _name(src._name), _signGrade(src._signGrade), _executeGrade(src._executeGrade)
{
	*this = src;
	std::cout << "Copy constructor called on AForm" << std::endl;
}

AForm& AForm::operator=(const AForm &src)
{
	this->_signed = src._signed;
	std::cout << "Copy assignment operator called on AForm" << std::endl;
	return (*this);

}

AForm::~AForm(void)
{
	std::cout << "Destructor called on AForm" << std::endl;
}

std::ostream& operator<<(std::ostream&out, const AForm &toPrint)
{
	out << toPrint.getName() << ". Form signed: " << toPrint.getSigned() << \
		". Grade needed to sign: " << toPrint.getSignGrade() << \
		". Grade needed to execute: " << toPrint.getExecuteGrade() << ".";
	return (out);
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int	AForm::getExecuteGrade() const
{
	return (this->_executeGrade);
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_signed = 1;
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	this->beExecuted();
}
