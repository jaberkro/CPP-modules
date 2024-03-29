/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:14 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/27 13:52:32 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	std::cout << "Default constructor called on Cat" << std::endl;
	this->_type = "Cat";
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
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Destructor called on Cat" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Purrrr" << std::endl;
}
