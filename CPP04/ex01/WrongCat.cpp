/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:57:52 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/17 16:43:55 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
	std::cout << "Default constructor called on WrongCat" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "Copy constructor called on WrongCat" << std::endl;
	*this = src;
}

WrongCat& WrongCat::operator=(const WrongCat &src)
{
	std::cout << "Copy assignment operator called on WrongCat" << std::endl;
	this->_type = src._type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor called on WrongCat" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Purrrr" << std::endl;
}
