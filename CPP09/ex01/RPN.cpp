#include "RPN.hpp"
#include <iostream>

RPN::RPN(void)
{
	// std::cout << "Default constructor called on RPN" << std::endl;
}

RPN::RPN(const RPN &src)
{
	// std::cout << "Copy constructor called on RPN" << std::endl;
	*this = src;
}

RPN& RPN::operator=(const RPN &src)
{
	// std::cout << "Copy assignment operator called on RPN" << std::endl;
	this->_stack = src._stack;
	return (*this);
}

RPN::~RPN(void)
{
	// std::cout << "Destructor called on RPN" << std::endl;
}

void	RPN::push_back(double d)
{
	this->_stack.push(d);
}

void	RPN::pop_back(void)
{
	this->_stack.pop();
}

double	RPN::getTop(void)
{
	return (this->_stack.top());
}

int	RPN::operation(char c)
{
	double a;
	double b;

	if (this->_stack.empty())
		return (0);
	a = this->_stack.top();
	this->_stack.pop();
	if (this->_stack.empty())
		return (0);
	b = this->_stack.top();
	this->_stack.pop();

	if (c == '+')
		this->_stack.push(b + a);
	if (c == '-')
		this->_stack.push(b - a);
	if (c == '/')
		this->_stack.push(b / a);
	if (c == '*')
		this->_stack.push(b * a);
	return (1);
}
