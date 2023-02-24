#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);

		class	GradeTooHighException;
		class	GradeTooLowException;

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream&out, const Bureaucrat &toPrint);

#endif
