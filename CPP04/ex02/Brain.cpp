/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 18:38:12 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/17 18:58:21 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "Default constructor called on Brain" << std::endl;
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
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Destructor called on Brain" << std::endl;
}

std::string	Brain::getIdea(int index) const
{
	return (this->_ideas[index]);
}

void	Brain::setIdea(int index, std::string idea)
{
	this->_ideas[index] = idea;
}
