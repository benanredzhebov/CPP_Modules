/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:44:31 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/13 11:14:41 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {
	std::string		str = "HI THIS IS BRAIN"; // string variable
	const char*		stringPTR = str.c_str(); // a pointer to the string
	std::string&	stringREF = str; // a reference to string
	
	/* Printing memory addresses */
	std::cout << "Memory address of the string variable: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR: " << static_cast<const void*>(stringPTR) << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
	
	/*Printin values*/
	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
}