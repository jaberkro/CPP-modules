#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm &src);
		AForm& operator=(const AForm &src);
		virtual ~AForm();

		std::string getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		void		beSigned(const Bureaucrat &b);

		virtual void		execute(Bureaucrat const& executor) const = 0;

		class	GradeTooHighException;
		class	GradeTooLowException;

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;
};

std::ostream& operator<<(std::ostream&out, const AForm &toPrint);

# include "Bureaucrat.hpp"
#endif
