/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 12:19:57 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/19 18:21:42 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed &fixed);
		Fixed & operator=(const Fixed &fixed);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
		bool	operator>(const Fixed &toCheck);
		bool	operator<(const Fixed &toCheck);
		bool	operator>=(const Fixed &toCheck);
		bool	operator<=(const Fixed &toCheck);
		bool	operator==(const Fixed &toCheck);
		bool	operator!=(const Fixed &toCheck);
		
		Fixed&	operator+(const Fixed &toAdd);
		Fixed&	operator-(const Fixed &toDistract);
		Fixed&	operator*(const Fixed &toMultiply);
		Fixed&	operator/(const Fixed &toDivide);

		// Fixed&	operator++(void);
		// Fixed	operator++(int i);

	private:
		int					_value;
		static const int 	_bits = 8;
};

std::ostream& operator<<(std::ostream&out, const Fixed &toPrint);

#endif
