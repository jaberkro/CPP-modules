/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 12:19:55 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/13 16:07:55 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	Fixed b(-5);
	Fixed c(5.3f);
	Fixed const d(Fixed(5.05f) * Fixed(2));
	Fixed const e(8.0f);

	std::cout << "_______\n" << std::endl;
	std::cout << "Starting values:\n" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "_______\n" << std::endl;
	
	//ADDITION
	std::cout << "Addition on a:\n" << std::endl;
	std::cout << a << std::endl;
	std::cout << a + 2 << std::endl;
	std::cout << a << std::endl;
	a = a + 2;
	std::cout << a << std::endl;
	std::cout << a + 20 << std::endl;
	std::cout << a << std::endl;
	std::cout << "_______\n" << std::endl;

	std::cout << "Addition on b:\n" << std::endl;
	std::cout << b << std::endl;
	std::cout << b + 2 << std::endl;
	std::cout << b << std::endl;
	b = b + 2;
	std::cout << b << std::endl;
	std::cout << b + 20 << std::endl;
	std::cout << b << std::endl;
	std::cout << "_______\n" << std::endl;

	std::cout << "Addition on c:\n" << std::endl;
	std::cout << c << std::endl;
	std::cout << c + 2 << std::endl;
	std::cout << c << std::endl;
	c = c + 2;
	std::cout << c << std::endl;
	std::cout << c + 20 << std::endl;
	std::cout << c << std::endl;
	std::cout << "_______\n" << std::endl;

	//SUBSTRACTION
	std::cout << "Substraction on a:\n" << std::endl;
	std::cout << a << std::endl;
	std::cout << a - 2 << std::endl;
	std::cout << a << std::endl;
	a = a - 2;
	std::cout << a << std::endl;
	std::cout << a - 20 << std::endl;
	std::cout << a << std::endl;
	std::cout << "_______\n" << std::endl;

	std::cout << "Substraction on b:\n" << std::endl;
	std::cout << b << std::endl;
	std::cout << b - 2 << std::endl;
	std::cout << b << std::endl;
	b = b - 2;
	std::cout << b << std::endl;
	std::cout << b - 20 << std::endl;
	std::cout << b << std::endl;
	std::cout << "_______\n" << std::endl;

	std::cout << "Substraction on c:\n" << std::endl;
	std::cout << c << std::endl;
	std::cout << c - 2 << std::endl;
	std::cout << c << std::endl;
	c = c - 2;
	std::cout << c << std::endl;
	std::cout << c - 20 << std::endl;
	std::cout << c << std::endl;
	std::cout << "_______\n" << std::endl;

	//MULTIPLICATION
	std::cout << "Multiplication on a:\n" << std::endl;
	std::cout << a << std::endl;
	std::cout << a * 2 << std::endl;
	std::cout << a << std::endl;
	a = a * 2;
	std::cout << a << std::endl;
	std::cout << a * 20 << std::endl;
	std::cout << a << std::endl;
	std::cout << "_______\n" << std::endl;

	std::cout << "Multiplication on b:\n" << std::endl;
	std::cout << b << std::endl;
	std::cout << b * 2 << std::endl;
	std::cout << b << std::endl;
	b = b * 2;
	std::cout << b << std::endl;
	std::cout << b * 20 << std::endl;
	std::cout << b << std::endl;
	std::cout << "_______\n" << std::endl;

	std::cout << "Multiplication on c:\n" << std::endl;
	std::cout << c << std::endl;
	std::cout << c * 2 << std::endl;
	std::cout << c << std::endl;
	c = c * 2;
	std::cout << c << std::endl;
	std::cout << c * 20 << std::endl;
	std::cout << c << std::endl;
	std::cout << "_______\n" << std::endl;

	//DIVISION
	std::cout << "Division on a:\n" << std::endl;
	std::cout << a << std::endl;
	std::cout << a / 2 << std::endl;
	std::cout << a << std::endl;
	a = a / 2;
	std::cout << a << std::endl;
	std::cout << a / 20 << std::endl;
	std::cout << a << std::endl;
	std::cout << "_______\n" << std::endl;

	std::cout << "Division on b:\n" << std::endl;
	std::cout << b << std::endl;
	std::cout << b / 2 << std::endl;
	std::cout << b << std::endl;
	b = b / 2;
	std::cout << b << std::endl;
	std::cout << b / 20 << std::endl;
	std::cout << b << std::endl;
	std::cout << "_______\n" << std::endl;

	std::cout << "Division on c:\n" << std::endl;
	std::cout << c << std::endl;
	std::cout << c / 2 << std::endl;
	std::cout << c << std::endl;
	c = c / 2;
	std::cout << c << std::endl;
	std::cout << c / 20 << std::endl;
	std::cout << c << std::endl;
	std::cout << "_______\n" << std::endl;

	//INCREMENTING & DECREMENTING
	std::cout << "Incrementing on a:\n" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << "_______\n" << std::endl;

	std::cout << "Decrementing on a:\n" << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << "_______\n" << std::endl;

	std::cout << "Incrementing on b:\n" << std::endl;
	std::cout << b << std::endl;
	std::cout << ++b << std::endl;
	std::cout << b << std::endl;
	std::cout << b++ << std::endl;
	std::cout << b << std::endl;
	std::cout << "_______\n" << std::endl;

	std::cout << "Decrementing on b:\n" << std::endl;
	std::cout << b << std::endl;
	std::cout << b-- << std::endl;
	std::cout << b << std::endl;
	std::cout << --b << std::endl;
	std::cout << b << std::endl;
	std::cout << "_______\n" << std::endl;

	std::cout << "Incrementing on c:\n" << std::endl;
	std::cout << c << std::endl;
	std::cout << ++c << std::endl;
	std::cout << c << std::endl;
	std::cout << c++ << std::endl;
	std::cout << c << std::endl;
	std::cout << "_______\n" << std::endl;

	std::cout << "Decrementing on c:\n" << std::endl;
	std::cout << c << std::endl;
	std::cout << c-- << std::endl;
	std::cout << c << std::endl;
	std::cout << --c << std::endl;
	std::cout << c << std::endl;
	std::cout << "_______\n" << std::endl;

	//MIN
	std::cout << "Min values:\n" << std::endl;
	std::cout << min( a, b ) << std::endl;
	std::cout << min( a, c ) << std::endl;
	std::cout << min( a, d ) << std::endl;
	std::cout << min( a, e ) << std::endl;
	std::cout << min( b, c ) << std::endl;
	std::cout << min( b, d ) << std::endl;
	std::cout << min( b, e ) << std::endl;
	std::cout << min( c, d ) << std::endl;
	std::cout << min( c, e ) << std::endl;
	std::cout << min( d, e ) << std::endl;
	std::cout << "_______\n" << std::endl;
	
	//MAX
	std::cout << "Max values:\n" << std::endl;
	std::cout << max( a, b ) << std::endl;
	std::cout << max( a, c ) << std::endl;
	std::cout << max( a, d ) << std::endl;
	std::cout << max( a, e ) << std::endl;
	std::cout << max( b, c ) << std::endl;
	std::cout << max( b, d ) << std::endl;
	std::cout << max( b, e ) << std::endl;
	std::cout << max( c, d ) << std::endl;
	std::cout << max( c, e ) << std::endl;
	std::cout << max( d, e ) << std::endl;
	std::cout << "_______\n" << std::endl;

	std::cout << "End values:\n" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "_______\n" << std::endl;

	return 0;
}
