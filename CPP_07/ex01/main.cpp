/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:56:50 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/10/28 22:18:50 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./iter.hpp"

int	main() {
	int		intArray[] = {1, 2, 3, 4, 5};
	char	charArray[] = {'a', 'b', 'c', 'd', 'e'};
	float	floatArray[] = {1.2f, 3.3333f, 0.0007f, 78, .2f};
	

	std::cout << "Int array: ";
	iter(intArray, 5, print);
	std::cout << std::endl;

	std::cout << "Char array: ";
	iter(charArray, 5, print);
	std::cout << std::endl;

	std::cout << "Char array: ";
	iter(floatArray, 5, print);
	std::cout << std::endl;

	return 0;
}