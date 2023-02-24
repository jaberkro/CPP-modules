#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class Form::GradeTooHighException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("This grade is too high!");
		}
};

class Form::GradeTooLowException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("This grade is too low!");
		}
};

Form::Form(std::string name, int signGrade, int executeGrade): _name(name), _signed(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Parametric constructor called on Form" << std::endl;
	try
	{
		if (signGrade < 1 || executeGrade < 1)
			throw Form::GradeTooHighException();
		else if (signGrade > 150 || executeGrade > 150)
			throw Form::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Form::~Form(void)
{
	std::cout << "Destructor called on Form" << std::endl;
}

std::ostream& operator<<(std::ostream&out, const Form &toPrint)
{
	out << toPrint.getName() << ". Form signed: " << toPrint.getSigned() << \
		". Grade needed to sign: " << toPrint.getSignGrade() << \
		". Grade needed to execute: " << toPrint.getExecuteGrade() << ".";
	return (out);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool		Form::getSigned() const
{
	return (this->_signed);
}

int			Form::getSignGrade() const
{
	return (this->_signGrade);
}

int			Form::getExecuteGrade() const
{
	return (this->_executeGrade);
}

int		Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_signGrade)
		return (0);

	this->_signed = 1;
	return (1);
}
