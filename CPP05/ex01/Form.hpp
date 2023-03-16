#ifndef FORM_HPP
# define FORM_HPP
# include <string>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form &src);
		Form& operator=(const Form &src);
		~Form();

		std::string getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		void		beSigned(const Bureaucrat &b);

		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;
};

std::ostream& operator<<(std::ostream&out, const Form &toPrint);

# include "Bureaucrat.hpp"
#endif
