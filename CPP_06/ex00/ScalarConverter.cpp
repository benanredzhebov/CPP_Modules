/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:43:16 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/10/21 18:14:35 by benanredzhe      ###   ########.fr       */
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

void	ScalarConverter::convert(const std::string& literal) {
	/*Handle special float literals*/
	if (literal == "-inf" || literal == "+inff" || literal == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: imposible" << std::endl;
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
		return;
	}
	/*Handle special double literals*/

	/*
	
	 if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }

    // Convert to char
    try {
        if (literal.length() == 1 && !isdigit(literal[0])) {
            char c = literal[0];
            std::cout << "char: '" << c << "'" << std::endl;
        } else {
            int i = std::atoi(literal.c_str());
            if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max()) {
                std::cout << "char: impossible" << std::endl;
            } else if (!isprint(static_cast<char>(i))) {
                std::cout << "char: Non displayable" << std::endl;
            } else {
                std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
            }
        }
    } catch (...) {
        std::cout << "char: impossible" << std::endl;
    }

    // Convert to int
    try {
        int i = std::atoi(literal.c_str());
        std::cout << "int: " << i << std::endl;
    } catch (...) {
        std::cout << "int: impossible" << std::endl;
    }

    // Convert to float
    try {
        float f = std::atof(literal.c_str());
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
    } catch (...) {
        std::cout << "float: impossible" << std::endl;
    }

    // Convert to double
    try {
        double d = std::atof(literal.c_str());
        std::cout << "double: " << d << std::endl;
    } catch (...) {
        std::cout << "double: impossible" << std::endl;
    }
}
	
	*/
}

