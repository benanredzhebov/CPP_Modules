/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:43:16 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/10/27 16:24:49 by beredzhe         ###   ########.fr       */
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

void ScalarConverter::convert(const std::string& literal) {
	// Handle special double literals
	if (literal == "-inf" || literal == "+inf" || literal == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return;
	}

	if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: imposible" << std::endl;
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
		return;
	}

	// Convert to char
	if (literal.length() == 1 && !isdigit(literal[0])) {
		char c = literal[0];
		int i = static_cast<int>(c);
		float f = static_cast<float>(c);
		double d = static_cast<double>(c);

		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else {
		// Assume the literal represents a number
		int i = atoi(literal.c_str());
		float f = atof(literal.c_str());
		double d = atof(literal.c_str());

		// Convert to char
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

		// Convert to int
		std::cout << "int: " << i << std::endl;

		// Convert to float
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

		// Convert to double
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
}