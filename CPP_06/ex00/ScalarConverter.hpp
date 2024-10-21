/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:31:35 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/10/21 17:50:39 by benanredzhe      ###   ########.fr       */
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
		ScalarConverter() {};                          //Private constructor to prevent instantiation
		ScalarConverter(const ScalarConverter &other); //Private constructor to prevent copy
		~ScalarConverter() {};                         //Private constructor to prevent instantiation

		ScalarConverter &operator=(const ScalarConverter &other) {}; // Private copy assignment operator to prevent copying
		
};

#endif