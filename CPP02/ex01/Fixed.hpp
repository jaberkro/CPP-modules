/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/18 12:19:57 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/19 17:19:07 by jaberkro      ########   odam.nl         */
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
		Fixed & operator = (const Fixed &fixed);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;


	private:
		int					_value;
		static const int 	_bits = 8;
};

std::ostream& operator<<(std::ostream&out, const Fixed &toPrint);

#endif
