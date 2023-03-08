#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include <string>

class Intern
{
	public:
		Intern();
		// Intern(const Intern &src);
		// Intern& operator=(const Intern &src);
		~Intern();

		AForm::AForm * makeForm(std::string formName, std::string target);
};

#endif
