/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 08:59:39 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/27 07:21:34 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other); // Copy constructor
		Fixed &operator=(const Fixed &other); // Copy assignment operator
		~Fixed();

		int		getRawBits( void ) const; // Returns the raw fixed-point value
		void	setRawBits( int const raw ); // Sets the raw fixed-point value
};

#endif