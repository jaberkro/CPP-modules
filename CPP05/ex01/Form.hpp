#ifndef FORM_HPP
# define FORM_HPP
# include <string>

class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int signGrade, int executeGrade);
		~Form();

		std::string getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		int		beSigned(const Bureaucrat &b);

		class	GradeTooHighException;
		class	GradeTooLowException;

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;
};

std::ostream& operator<<(std::ostream&out, const Form &toPrint);

# include "Bureaucrat.hpp"
#endif
