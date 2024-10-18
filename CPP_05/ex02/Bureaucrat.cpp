/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:52:41 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/18 11:03:52 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Defaulf name"), _grade(150) {
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat constructor with name called" << std::endl;
	try {
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
		else {
			std::cout << getName() << " with grade level " << getGrade() << " is now available" << std::endl;
		}
	}
	catch(const std::exception &ex) {
		std::cerr << "Exception thrown for Bureacrat " << getName() << ex.what();
		_grade = 150;
		std::cout << "Bureaucrat " << getName() << " with grade level " << getGrade() << " is now available" << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(other.getGrade()) { 
	std::cout << "Bureaucrat copy constructor called! " << _name << " is now also available" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Default destructor called! " << _name << " left" << std::endl;
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	try {
		if (_grade <= 1) 
			throw GradeTooHighException();
		else
			_grade--;
		std::cout << getName() << " is upgraded to grade " << getGrade() << std::endl;
	}
	catch(const std::exception &ex){
		std::cerr << "Exception thrown for Bureaucrat " << getName() << ex.what();
	}
}

void Bureaucrat::decrementGrade() {
	try {
		if (_grade >= 150)
		throw GradeTooLowException();
	else
		_grade++;
	std::cout << getName() << " is downgraded to grade " << getGrade() << std::endl;
	}
	catch(const std::exception &ex) {
		std::cerr << "Exception thrown for Bureaucrat " << getName() << ex.what();
	}
}

void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << " form" <<std::endl;
	}
	catch (std::exception const &ex) {
		std::cout << getName() << " couldn't sign " << form.getName() << " form" \
			<< " because he doesn't have clearance" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) {
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
    {
		std::cerr << "Execution by " << this->_name << " failed with message "<< e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}