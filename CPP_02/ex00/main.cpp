/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:51:47 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/25 11:03:39 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <iostream>

int	main( void ) {
Fixed	a;
Fixed	b( a );
Fixed	c;
c = b;

std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;

return 0;
}


/*Fixed a; 		→ Default constructor called (for a)
Fixed b(a);		→ Copy constructor called (for b)
Fixed c; 		→ Default constructor called (for c)
c = b; 			→ Copy assignment operator called
a.getRawBits(); → getRawBits member function called (for a), prints 0
b.getRawBits(); → getRawBits member function called (for b), prints 0
c.getRawBits(); → getRawBits member function called (for c), prints 0
Program ends	→ Destructor called three times (once for a, b, and c)*/