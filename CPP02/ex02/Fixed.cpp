/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 12:20:00 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/19 18:21:33 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int input) : _value(input << this->_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float input) : _value(roundf(input * pow(2, 8)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed & Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (this->_value / (pow(2, 8)));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> _bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed &toPrint)
{
	out << toPrint.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &toCheck)
{
	if (this->_value > toCheck._value)
		return (1);
	return (0);
}

bool Fixed::operator<(const Fixed &toCheck)
{
	if (this->_value < toCheck._value)
		return (1);
	return (0);
}

bool Fixed::operator>=(const Fixed &toCheck)
{
	if (this->_value >= toCheck._value)
		return (1);
	return (0);
}

bool Fixed::operator<=(const Fixed &toCheck)
{
	if (this->_value <= toCheck._value)
		return (1);
	return (0);
}

bool Fixed::operator==(const Fixed &toCheck)
{
	if (this->_value == toCheck._value)
		return (1);
	return (0);
}

bool Fixed::operator!=(const Fixed &toCheck)
{
	if (this->_value != toCheck._value)
		return (1);
	return (0);
}

Fixed&	Fixed::operator+(const Fixed &toAdd)
{
	this->_value += toAdd._value;
	return (*this);
}

Fixed&	Fixed::operator-(const Fixed &toDistract)
{
	this->_value -= toDistract._value;
	return (*this);
}

Fixed&	Fixed::operator*(const Fixed &toMultiply)
{
	this->_value *= toMultiply._value;
	return (*this);
}

Fixed&	Fixed::operator/(const Fixed &toDivide)
{
	this->_value -= toDivide._value;
	return (*this);
}

// Fixed&	Fixed::operator++(void)
// {
// 	this->_value += 1;
// 	return (*this);
// }

// Fixed	Fixed::operator++(int previous)
// {
// 	previous = this->_value;
// 	this->_value = this->_value  + 1;
// 	return (previous);
// }


