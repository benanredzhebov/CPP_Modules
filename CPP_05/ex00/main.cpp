/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:48:59 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/22 11:03:39 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*The constructors initialize the Bureaucrat objects and validate the grades.
The incrementGrade and decrementGrade methods adjust the grades and handle
exceptions when the grades go out of bounds.
The << operator prints the current state of the Bureaucrat objects.
The destructors are called when the objects go out of scope, printing a message
indicating the object is being destroyed.*/

void testValidBureaucrat() {
	try {
		Bureaucrat b1("Alice", 2);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade(); // This should throw an exception
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testLowGradeBureaucrat() {
	try {
		Bureaucrat b2("Bob", 149);
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
		b2.decrementGrade(); // This should throw an exception
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testInvalidHighGradeBureaucrat() {
	try {
		Bureaucrat b3("Charlie", 0); // This should throw an exception
		std::cout << b3 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testInvalidLowGradeBureaucrat() {
	try {
		Bureaucrat b4("David", 151); // This should throw an exception
		std::cout << b4 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testBoundaryGrades() {
	try {
		Bureaucrat b5("Eve", 1);
		std::cout << b5 << std::endl;
		b5.incrementGrade(); // This should throw an exception
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat b6("Frank", 150);
		std::cout << b6 << std::endl;
		b6.decrementGrade(); // This should throw an exception
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

int main() {
	std::cout << "Testing valid Bureaucrat:" << std::endl;
	testValidBureaucrat();

	std::cout << "\nTesting low grade Bureaucrat:" << std::endl;
	testLowGradeBureaucrat();

	std::cout << "\nTesting invalid high grade Bureaucrat:" << std::endl;
	testInvalidHighGradeBureaucrat();

	std::cout << "\nTesting invalid low grade Bureaucrat:" << std::endl;
	testInvalidLowGradeBureaucrat();

	std::cout << "\nTesting boundary grades:" << std::endl;
	testBoundaryGrades();

	return 0;
}