#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe(void)
{
	std::cout << "Default constructor called on PmergeMe" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	std::cout << "Copy constructor called on PmergeMe" << std::endl;
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src)
{
	std::cout << "Copy assignment operator called on PmergeMe" << std::endl;
	// this->_array = src._array;
	// this->_vector = src.vector;
	(void)src;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	std::cout << "Destructor called on PmergeMe" << std::endl;
}
