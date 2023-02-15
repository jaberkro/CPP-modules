/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 12:20:00 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/15 22:19:59 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(input << this->_bits);
}

Fixed::Fixed(const float input)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(input * (1 << this->_bits)));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed)
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
	return (this->_value * 1.0 / (1 << _bits));
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

bool Fixed::operator>(const Fixed &toCheck) const
{
	return (this->_value > toCheck._value);
}

bool Fixed::operator<(const Fixed &toCheck) const
{
	return (toCheck > *this);
}

bool Fixed::operator>=(const Fixed &toCheck) const
{
	return (!(*this < toCheck));
}

bool Fixed::operator<=(const Fixed &toCheck) const
{
	return (!(*this > toCheck));
}

bool Fixed::operator==(const Fixed &toCheck) const
{
	return (this->_value == toCheck._value);
}

bool Fixed::operator!=(const Fixed &toCheck) const
{
	return (!(*this == toCheck));
}

Fixed	Fixed::operator+(const Fixed &toAdd) const
{
	Fixed result;
	result._value = this->getRawBits() + toAdd.getRawBits();
	return (result);
}

Fixed	Fixed::operator-(const Fixed &toSubstract) const
{
	Fixed result;
	result._value = this->getRawBits() - toSubstract.getRawBits();
	return (result);
}

Fixed	Fixed::operator*(const Fixed &toMultiply) const
{
	Fixed result;
	result._value = (this->toFloat() * toMultiply.toFloat()) * (1 << this->_bits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed &toDivide) const
{
	Fixed result;
	result._value = (this->toFloat() / toDivide.toFloat()) * (1 << this->_bits);
	return (result);
}

Fixed&	Fixed::operator++(void)
{
	++this->_value;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	--this->_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_value;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_value;
	return (temp);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	return (b);
}
