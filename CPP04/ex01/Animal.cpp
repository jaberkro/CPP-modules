/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:20 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/22 20:34:40 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void): _type("Animal")
{
	std::cout << "Default constructor called on Animal" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Copy constructor called on Animal" << std::endl;
	*this = src;
}

Animal& Animal::operator=(const Animal &src)
{
	std::cout << "Copy assignment operator called on Animal" << std::endl;
	this->_type = src._type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Destructor called on Animal" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound(void) const
{
	std::cout << "*silence*" << std::endl;
}

std::string	Animal::getIdea(int index) const
{
	return ("no clue");
}

void	Animal::setIdea(std::string idea)
{
	std::cout << "An animal has no brain. Not possible to set idea" << std::endl;
}

int	Animal::countIdeas(void) const
{
	std::cout << "An animal has no brain and no ideas" << std::endl;
	return (0);
}
