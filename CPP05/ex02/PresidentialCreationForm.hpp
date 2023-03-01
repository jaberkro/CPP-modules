#ifndef PRESIDENTIALCREATIONFORM_HPP
# define PRESIDENTIALCREATIONFORM_HPP
# include "AForm.hpp"

class PresidentialCreationForm: public AForm
{
	public:
		PresidentialCreationForm();
		PresidentialCreationForm(const PresidentialCreationForm &src);
		PresidentialCreationForm& operator=(const PresidentialCreationForm &src);
		~PresidentialCreationForm();

		virtual void	execute(Bureaucrat const& executor) const;

	private:

};

#endif
