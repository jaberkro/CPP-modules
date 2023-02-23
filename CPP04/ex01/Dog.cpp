/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:09 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/23 16:35:47 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(void)
{
	std::cout << "Default constructor called on Dog" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &src)
{
	std::cout << "Copy constructor called on Dog" << std::endl;
	*this = src;
}

Dog& Dog::operator=(const Dog &src)
{
	std::cout << "Copy assignment operator called on Dog" << std::endl;
	this->_type = src._type;
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		this->setIdea(src.getIdea(i));
	}
	this->_brain->setIndex(src.countIdeas());
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Destructor called on Dog" << std::endl;
	delete this->_brain;
}

void Dog::makeSound(void) const
{
	std::cout << "Woofff" << std::endl;
}

std::string	Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

void	Dog::setIdea(std::string idea)
{
	this->_brain->setIdea(idea);
}

int	Dog::countIdeas(void) const
{
	if (this->_brain->getIndex() > 100)
		return (100);
	return (this->_brain->getIndex());
}
