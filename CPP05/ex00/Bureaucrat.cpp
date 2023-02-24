#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat::GradeTooHighException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("This grade is too high for a bureaucrat! Set to highest possible: 1");
		}
};

class Bureaucrat::GradeTooLowException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("This grade is too low for a bureaucrat! Set to lowest possible: 150");
		}
};

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	std::cout << "Parametric constructor called on Bureaucrat" << std::endl;
	try
	{
		if (grade < 1)
		{
			this->_grade = 1;
			throw Bureaucrat::GradeTooHighException();
		}
		else if (grade > 150)
		{
			this->_grade = 150;
			throw Bureaucrat::GradeTooLowException();
		}
		else
		{
			this->_grade = grade;
		}
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
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
