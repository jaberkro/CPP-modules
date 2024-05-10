#include "Span.hpp"
#include <iostream>
#include <algorithm>

const char* Span::IndexOutOfRangeException::what() const throw()
{
	return ("Exception: Span is full");
}

const char* Span::TooSmallException::what() const throw()
{
	return ("Exception: Span too small to execute this function");
}

Span::Span(void)
{
	std::cout << "Default constructor called on Span" << std::endl;
	this->_vector.reserve(0);
}

Span::Span(unsigned int N)
{
	std::cout << "Parametric constructor called on Span" << std::endl;
	this->_vector.reserve(N);
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
	return (*this);
}

Span::~Span(void)
{
	std::cout << "Destructor called on Span" << std::endl;
}

void	Span::addNumber(int n)
{
	if (this->_vector.size() == this->_vector.capacity())
		throw IndexOutOfRangeException();
	this->_vector.push_back(n);
}

int		Span::shortestSpan(void)
{
	unsigned int 		shortestDist =  4294967295;
	std::vector<int> 	copy = this->_vector;

	if (this->_vector.size() < 2)
		throw TooSmallException();
	std::sort(copy.begin(), copy.end());
	for (std::vector<int>::size_type i = 0; i < copy.size() - 1; i++)
	{
		if (static_cast<unsigned int>(copy.at(i + 1) - copy.at(i)) < shortestDist)
			shortestDist = copy.at(i + 1) - copy.at(i);
	}
	copy.clear();
	return (shortestDist);
}

int		Span::longestSpan(void)
{
	std::vector<int> copy = this->_vector;

	if (this->_vector.size() < 2)
		throw TooSmallException();
	std::sort(copy.begin(), copy.end());
	int dist = copy.back() - copy.front();
	copy.clear();
	return (dist);
}

const std::vector<int> &Span::getVector(void) const
{
	return (this->_vector);
}

void	Span::addIncrementingNumbers(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end, int startNumber)
{
	while(start != end)
	{
		addNumber(startNumber);
		start++;
		startNumber++;
	}
}
