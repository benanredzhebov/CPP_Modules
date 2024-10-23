/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:31:35 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/10/23 13:28:34 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>

class ScalarConverter {
	public:
		static void convert(const std::string& literal);
	
	private:
		ScalarConverter();                          //Private constructor to prevent instantiation
		ScalarConverter(const ScalarConverter &other); //Private constructor to prevent copy
		~ScalarConverter();                         //Private constructor to prevent instantiation

		ScalarConverter &operator=(const ScalarConverter &other); // Private copy assignment operator to prevent copying
		
		// static bool isValidNumber(const std::string& str);
};

#endif