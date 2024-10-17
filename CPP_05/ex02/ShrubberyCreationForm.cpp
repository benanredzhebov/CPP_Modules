/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:24:35 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/17 14:48:36 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ShrubberyCreationForm.hpp"

Shrubbery::Shrubbery() : AForm("Shrubbery Form", 145, 137), _target("Default target") {
	std::cout << "Shrubbery dflt constructor called" << std::endl;
}

Shrubbery::Shrubbery(const std::string &target) : AForm("Shrubbery Form", 145, 137), _target(target) {
	std::cout << "Shrubbery parametrized constructor called" << std::endl;
}

Shrubbery::Shrubbery(const Shrubbery &other) : AForm(other), _target(other._target) {
	std::cout << "Shrubbery copy constructor called" << std::endl;
}

Shrubbery::~Shrubbery() {
	std::cout << "Shrubbery dflt destructor called" << std::endl;
}

Shrubbery &Shrubbery::operator=(const Shrubbery &other) {
	std::cout << "Shrubbery copy assignment operator called" << std::endl;
	if (this != &other){
		AForm::operator=(other);
		_target = other._target;
	}	
	return *this;
}

std::string Shrubbery::getTarget() const {
	return _target;
}

