/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:56:50 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/11/01 08:33:17 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./iter.hpp"

int	main() {
	int			intArray[5] = {1, 2, 3, 4, 5};
	char		charArray[5] = {'a', 'b', 'c', 'd', 'e'};
	std::string	stringArray[3] = {"Benan", "Dorukhan", "Defne"};
	float		floatArray[5] = {1.2f, 3.3333f, 0.0007f, 78, .2f};
	

	std::cout << "Int array: ";
	iter(intArray, 5, print);
	std::cout << std::endl;

	std::cout << "Char array: ";
	iter(charArray, 5, print);
	std::cout << std::endl;

	std::cout << "String array: ";
	iter(stringArray, 3, print);
	std::cout << std::endl;

	std::cout << "Float array: ";
	iter(floatArray, 5, print);
	std::cout << std::endl;

	return 0;
}