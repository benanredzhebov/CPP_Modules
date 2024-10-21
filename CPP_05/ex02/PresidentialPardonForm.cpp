/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:05:50 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/21 10:26:25 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Defailt") {
	std::cout << "PresidentialPardonForm Dflt constructor called" << std::endl;
} 

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm parametrized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target) {
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm Dflt destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other){
		// AForm::operator=(other);
		_target = other._target;
		AForm::operator=(other);
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget() const {
	return _target;
}

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	try {
		if (!this->getIsSigned())
			throw(AForm::FormNotSignedException());
		else if (executor.getGrade() > this->getGradeToExecute())
			throw(AForm::GradeTooLowException());
		else
			this->executeForm();
	}
	catch (const std::exception &ex) {
		std::cerr << "Exeption thrown: " << ex.what() << std::endl;
	}
}

void PresidentialPardonForm::executeForm() const {
	std::cout <<getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}