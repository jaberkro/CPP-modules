#include "Span.hpp"
#include <iostream>
#include <algorithm>

const char* Span::IndexOutOfRangeException::what() const throw()
{
	return ("Exception: Span already filled");
}

const char* Span::TooSmallException::what() const throw()
{
	return ("Exception: Span too smal");
}

Span::Span(void)
{
	this->_vector.resize(0);
	this->_index = 0;
	std::cout << "Default constructor called on Span" << std::endl;
}

Span::Span(unsigned int N)
{
	this->_vector.resize(N);
	this->_index = 0;
	std::cout << "Parametric constructor called on Span" << std::endl;
}

Span::Span(const Span &src)
{
	std::cout << "Copy constructor called on Span" << std::endl;
	*this = src;
}

Span& Span::operator=(const Span &src)
{
	std::cout << "Copy assignment operator called on Span" << std::endl;
	this->_vector = src._vector;
	this->_index = src._index;
	return (*this);
}

Span::~Span(void)
{
	std::cout << "Destructor called on Span" << std::endl;
}

void	Span::addNumber(int n)
{
	if (this->_index >= this->_vector.size())
		throw IndexOutOfRangeException();
	this->_vector.at(this->_index) = n;
	this->_index++;
}

int		Span::shortestSpan(void)
{
	unsigned int	shortestDist =  4294967295;
	std::vector<int> copy = this->_vector;

	if (this->_vector.size() < 2)
		throw TooSmallException();
	std::sort(copy.begin(), copy.end());
	for (unsigned long i = 0; i < copy.size() - 1; i++)
	{
		if ((unsigned int)(copy.at(i + 1) - copy.at(i)) < shortestDist)
			shortestDist = copy.at(i + 1) - copy.at(i);
	}
	copy.clear();
	return (shortestDist);
}

int		Span::longestSpan(void)
{
	std::vector<int> copy = this->_vector;
	int	dist;

	if (this->_vector.size() < 2)
		throw TooSmallException();
	std::sort(copy.begin(), copy.end());
	dist = copy.back() - copy.front();
	copy.clear();
	return (dist);
}
