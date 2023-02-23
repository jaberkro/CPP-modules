/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 18:58:14 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/23 16:21:22 by jaberkro      ########   odam.nl         */
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
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		this->setIdea(src.getIdea(i));
	}
	this->_brain->setIndex(src.countIdeas());
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

std::string	Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

void	Cat::setIdea(std::string idea)
{
	this->_brain->setIdea(idea);
}

int	Cat::countIdeas(void) const
{
	if (this->_brain->getIndex() > 100)
		return (100);
	return (this->_brain->getIndex());
}
