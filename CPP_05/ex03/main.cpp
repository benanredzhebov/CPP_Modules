/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 08:59:39 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/18 12:16:02 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// int main() {
// 	try {
// 		Bureaucrat officer("Officer", 1);
// 		Bureaucrat middleManager("Middle Manager", 50);
// 		Bureaucrat chef("Chef", 150);

// 		ShrubberyCreationForm formA("home");
// 		RobotomyRequestForm formB("office");
// 		PresidentialPardonForm formC("prisoner");

// 		officer.signForm(formA);
// 		officer.executeForm(formA);  // Officer can execute the signed form

// 		middleManager.signForm(formB);
// 		middleManager.executeForm(formB);  // Manager can't execute this form because it is not signed.

// 		officer.signForm(formB);
// 		officer.executeForm(formB);  // Officer cannot execute the form because of his low grade.

// 		middleManager.executeForm(formB);  // Manager should be able to execute the form.

// 		chef.signForm(formC);
// 		chef.executeForm(formC);  // Chef cannot execute the form because of his low grade.

// 		// Test Intern
// 		Intern someRandomIntern;
// 		AForm* rrf;
// 		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
// 		if (rrf) {
// 			officer.signForm(*rrf);
// 			officer.executeForm(*rrf);
// 			delete rrf;
// 		}

// 		rrf = someRandomIntern.makeForm("unknown form", "Bender");
// 		if (rrf) {
// 			delete rrf;
// 		}
// 	} catch (std::exception &e) {
// 		std::cerr << e.what() << std::endl;
// 	}

// 	return 0;
// }

int main()
{
	Intern guy;
	
	// pointers to abstract classes are used for polymorphism and dynamic object creation. 
	// Polymorphism allows you to work with objects of different derived classes through a 
	// common interface provided by the base class:
	AForm* rrf;
	
	rrf = guy.makeForm("shrubbery creation", "olaf bender");
	std::cout << *rrf << std::endl << std::endl;
	// delete called on 'AForm' that is abstract but has non-virtual destructor 
	// [-Werror,-Wdelete-abstract-non-virtual-dtor]
	delete rrf; // AVOID MEMORY LEAKS !!!

	rrf = guy.makeForm("presidential pardon", "olaf bender");
	std::cout << *rrf << std::endl << std::endl;
	delete rrf;

	rrf = guy.makeForm("robotomy request", "olaf bender");
	std::cout << *rrf << std::endl << std::endl;
	delete rrf;

	rrf = guy.makeForm("someStupidForm", "olaf bender");
	if (rrf) {
   		 std::cout << *rrf << std::endl << std::endl;
    delete rrf;
	}
	
	std::cout << std::endl;
}