#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Exception: Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Exception: Grade too low");
}

Form::Form(): _name("Nameless"), _signed(0), _signGrade(150), _executeGrade(150)
{
	std::cout << "Default constructor called on Form" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade): _name(name), _signed(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Parametric constructor called on Form" << std::endl;
}

Form::Form(const Form &src): _name(src._name), _signGrade(src._signGrade), _executeGrade(src._executeGrade)
{
	*this = src;
	std::cout << "Copy constructor called on Form" << std::endl;
}

Form& Form::operator=(const Form &src)
{
	this->_signed = src._signed;
	std::cout << "Copy assignment operator called on Form" << std::endl;
	return (*this);
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

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

int	Form::getExecuteGrade() const
{
	return (this->_executeGrade);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_signed = 1;
}
