/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 12:19:57 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/02/15 22:16:12 by jaberkro      ########   odam.nl         */
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
		Fixed& operator=(const Fixed &fixed);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
		bool	operator>(const Fixed &toCheck) const;
		bool	operator<(const Fixed &toCheck) const;
		bool	operator>=(const Fixed &toCheck) const;
		bool	operator<=(const Fixed &toCheck) const;
		bool	operator==(const Fixed &toCheck) const;
		bool	operator!=(const Fixed &toCheck) const;
		
		Fixed	operator+(const Fixed &toAdd) const;
		Fixed	operator-(const Fixed &toSubstract) const;
		Fixed	operator*(const Fixed &toMultiply) const;
		Fixed	operator/(const Fixed &toDivide) const;

		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed&		min(Fixed &a, Fixed &b);
		static const Fixed&	min(const Fixed &a, const Fixed &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		static const Fixed&	max(const Fixed &a, const Fixed &b);

	private:
		int					_value;
		static const int 	_bits = 8;
};

std::ostream& 	operator<<(std::ostream&out, const Fixed &toPrint);

#endif
