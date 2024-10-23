/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:43:16 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/10/23 13:52:59 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Default destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

/*Checks if input is a valid number that can be converted to a double*/
// bool ScalarConverter::isValidNumber(const std::string& str) {
// 	char* end;
// 	std::strtod(str.c_str(), &end);
// 	return end != str.c_str() && *end == '\0';
// }


void	ScalarConverter::convert(const std::string& literal) {
	
	
	/*Handle special float literals*/
	if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: imposible" << std::endl;
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
		return;
	}
	/*Handle special double literals*/
	if (literal == "-inf" || literal == "+inf" || literal == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return;
	}

	/*Check if the input is more than one character and not a valid number*/
	// if (literal.length() > 1 && !isValidNumber(literal)) {
	// 	std::cout << "invalid string input" << std::endl;
	// 	return;
	// }

	// Convert to char
	if (literal.length() == 1 && !isdigit(literal[0])) {
		char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else {
		/*if literal is not single-non digit character, the code assumes that literal represents a number*/
		int i = std::atoi(literal.c_str());
		/*Check if i can be represented as a char. Min value for char is -128, unsigned is 0, max signed 127, unsigned 255 */
		if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max()) {
			std::cout << "char: impossible" << std::endl;
		}
		/*If i is within the valid range for a char, the program checks if the character is printable using isprint().*/
		else if (!isprint(static_cast<char>(i))) {
			std::cout << "char: Non displayable" << std::endl;
		}
		/*Printing tha valid character*/
		else {
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		}
	}

	// Convert to int
	try {
		int i = static_cast<int>(std::atoi(literal.c_str()));
		std::cout << "int: " << i << std::endl;
	} catch (const std::exception &e) {
		std::cout << "int: impossible" << std::endl;
	}

	// Convert to float
	try {
		float f = static_cast<float>(std::atof(literal.c_str()));
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "float: impossible" << std::endl;
	}

	// Convert to double
	try {
		double d = static_cast<double>(std::atof(literal.c_str()));
		std::cout << "double: " << d << std::endl;
	} catch (const std::exception &e) {
		std::cout << "double: impossible" << std::endl;
	}
}
