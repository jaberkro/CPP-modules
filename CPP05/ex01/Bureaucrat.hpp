#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat& operator=(const Bureaucrat &src);
		~Bureaucrat();

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);

		void		signForm(Form& form);

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
		int					_grade;
};

std::ostream& operator<<(std::ostream&out, const Bureaucrat &toPrint);

# include "Form.hpp"
#endif
