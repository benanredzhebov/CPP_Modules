/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:27:54 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/25 11:53:07 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int				_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int value); // Constructor for int
		Fixed(const float value); // Constructor for float
		Fixed(const Fixed &other); // Copy constructor
		~Fixed();

		Fixed &operator=(const Fixed &other); // Copy assignment operator		

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

/* Overload the << operator*/
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif