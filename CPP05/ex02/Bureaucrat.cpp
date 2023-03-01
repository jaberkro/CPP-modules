#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception: Grade too low");
}

Bureaucrat::Bureaucrat(): _name("Nameless"), _grade(150)
{
	std::cout << "Default constructor called on Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << "Parametric constructor called on Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
	std::cout << "Copy constructor called on Bureaucrat" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	// this->_name = src.getName(); // hoe dit op te lossen?
	this->_grade = src._grade;
	std::cout << "Copy assignment operator called on Bureaucrat" << std::endl;
	return (*this);

}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called on Bureaucrat" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &toPrint)
{
	out << toPrint.getName() << ", bureaucrat grade " << toPrint.getGrade();
	return (out);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void		Bureaucrat::incrementGrade(void)
{
	if (this->_grade > 1)
		this->_grade--;
}

void		Bureaucrat::decrementGrade(void)
{
	if (this->_grade < 150)
		this->_grade++;
}


void	Bureaucrat::signForm(AForm& aform)
{
	try
	{
		aform.beSigned(*this);
		std::cout << *this << " signed " << aform << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " couldn't sign " << aform << " because ";
		std::cerr << e.what() << '\n';
	}
}
