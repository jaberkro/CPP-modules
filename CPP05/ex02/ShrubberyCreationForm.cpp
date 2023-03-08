#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "Nowhere";
	std::cout << "Default constructor called on ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
	std::cout << "Parametric constructor called on ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{
	*this = src;
	std::cout << "Copy constructor called on ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	this->_target = src._target;
	std::cout << "Copy assignment operator called on ShrubberyCreationForm" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor called on ShrubberyCreationForm" << std::endl;
}

void		ShrubberyCreationForm::beExecuted(void) const
{
	std::ofstream	file;
	std::string		fileName;

	fileName = this->_target;
	file.open(fileName.append("_shrubbery"));
	if (!file.is_open())
	{
		std::cout << "Error: not possible to create file" << std::endl;
	}
	else
	{
		file << "\n			   ,@@@@@@@," << std::endl;
		file << "	   ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		file << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
		file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
		file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
		file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
		file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
		file << "	   |o|        | |         | |" << std::endl;
		file << "	   |.|        | |         | |" << std::endl;
		file << "    \\\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	}
}
