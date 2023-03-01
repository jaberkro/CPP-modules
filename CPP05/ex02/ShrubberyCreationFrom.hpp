#ifndef SHRUBBERYCREATIONFROM_HPP
# define SHRUBBERYCREATIONFROM_HPP
# include "AForm.hpp"

class ShrubberyCreationFrom: public AForm
{
	public:
		ShrubberyCreationFrom();
		ShrubberyCreationFrom(const ShrubberyCreationFrom &src);
		ShrubberyCreationFrom& operator=(const ShrubberyCreationFrom &src);
		~ShrubberyCreationFrom();

		virtual void		execute(Bureaucrat const& executor) const;

	private:

};

#endif
