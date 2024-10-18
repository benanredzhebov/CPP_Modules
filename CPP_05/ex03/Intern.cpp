/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:49:11 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/18 12:08:35 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	*this = other;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

AForm* createShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
	struct FormType {
		std::string name;
		AForm* (*create)(const std::string &target);
	};
	
	FormType formTypes[] = {
		{"shrubbery creation", createShrubberyCreationForm},
		{"robotomy request", createRobotomyRequestForm},
		{"presidential pardon", createPresidentialPardonForm}
	};

	for (int i = 0; i < 3; ++i) {
		if (formTypes[i].name == formName) {
			std::cout << "Intern creates" << formName << std::endl;
			return formTypes[i].create(target);
		}
	}
	std::cout << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
	return NULL;
}