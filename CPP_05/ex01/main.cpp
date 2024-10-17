/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:48:59 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/17 11:51:47 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        // Create Bureaucrats
        Bureaucrat alice("Alice", 2);
        Bureaucrat bob("Bob", 149);

        // Create Forms
        Form formA("FormA", 1, 50); // requires a grade of 1 to sign and 50 to execute
        Form formB("FormB", 150, 150);

        // Display initial states
        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << formA << std::endl; // they should be unsigned because they have not been signed by any bureaucrat yet
        std::cout << formB << std::endl; //t hey should be unsigned because they have not been signed by any bureaucrat yet

        // Try to sign forms
        alice.signForm(formA);
        bob.signForm(formB);

        // Try to sign forms with insufficient grade
        bob.signForm(formA);   // Should fail

        // Display final states
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        // Test grade increment and decrement
        alice.incrementGrade(); // Should throw an exception
        bob.decrementGrade();   // Should succeed
        bob.decrementGrade();   // Should throw an exception

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}