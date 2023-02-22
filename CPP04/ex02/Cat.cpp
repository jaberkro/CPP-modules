/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:14 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/17 19:09:50 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat(void)
{
	std::cout << "Default constructor called on Cat" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &src)
{
	std::cout << "Copy constructor called on Cat" << std::endl;
	*this = src;
}

Cat& Cat::operator=(const Cat &src)
{
	std::cout << "Copy assignment operator called on Cat" << std::endl;
	this->_type = src._type;
	this->_brain = src._brain;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Destructor called on Cat" << std::endl;
	delete this->_brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Purrrr" << std::endl;
}
