/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntegerClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:21:56 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/20 10:26:18 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_CLASS_HPP
# define INTEGER_CLASS_HPP

# include <iostream>

class Integer {
	public:
		Integer ( int const n );
		~Integer( void );

		int getValue( void ) const;

		Integer &	operator+( Integer const & rhs);
		Integer		operator+( Integer const & rhs ) const;

		private:
			int	_n;
};

std::ostream &	operator<<( std::ostream & o, Integer const & rhs );

#endif
