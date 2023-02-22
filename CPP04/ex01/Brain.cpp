/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 18:38:12 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/22 20:54:35 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void): _index(0)
{
	std::cout << "Default constructor called on Brain" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = "";
	}
}

Brain::Brain(const Brain &src)
{
	std::cout << "Copy constructor called on Brain" << std::endl;
	*this = src;
}

Brain& Brain::operator=(const Brain &src)
{
	std::cout << "Copy assignment operator called on Brain" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = src._ideas[i];
	}
	this->_index = src._index;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Destructor called on Brain" << std::endl;
}

std::string	Brain::getIdea(int index) const
{
	return (this->_ideas[index % 100]);
}

void	Brain::setIdea(std::string idea)
{
	this->_ideas[this->_index % 100] = idea;
	this->_index++;
}

int	Brain::getIndex(void) const
{
	return (this->_index);
}

void	Brain::setIndex(int const index)
{
	if (index >= 0 && index <= 99)
		this->_index = index;
	else
		std::cout << "Impossible to set index: value out of range [0-99]" << std::endl;
}
