/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:15:32 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/20 10:15:33 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "./IntegerClass.hpp"

int	main() {
	Integer	x( 30 );
	Integer	y( 10 );
	Integer z( 0  );

	std::cout << "Value of x : " << x << std::endl;
	std::cout << "Value of y : " << y << std::endl;
	y = Integer( 12 );
	std::cout << "Value of y : " << y << std::endl;

	std::cout << "Value of z : " << z << std::endl;
	z = x + y;
	std::cout << "Value of z : " << z << std::endl;

	return 0;
}
