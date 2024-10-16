/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:43:03 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/16 14:15:16 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"

Form::Form() : _name("Default"), _isSigned(false),
				_gradeToSign(150), _gradeToExecute(150) {
					std::cout << "Default constructor called" << getName() << " Form with sign grade " \
						<< getGradeToSign() << " and execution grade " << getGradeToExecute() << " is printed" << std::endl; 
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name),
		_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
			std::cout << "Form with parameters called" << std::endl;
			try {
				if (gradeToSign > 150 || gradeToExecute > 150)
					throw GradeTooLowException();
				else if (gradeToSign < 1 || gradeToExecute < 1)
					throw GradeTooHighException();
				else {
					std::cout << getName() << " Form with sign grade " \
						<< getGradeToSign() << " and execution grade " << getGradeToExecute() << " is printed" << std::endl;
				}
			}
			catch(const std::exception &ex) {
				std::cerr << "Exception thrown for " << getName() << " Form " << ex.what();
			}
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), \
		_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)  {
	std::cout << "Form copy constructor called. " << getName() << " Form with sign grade " \
		<< getGradeToSign() << " and execution grade " << getGradeToExecute() << " is photocopied" << std::endl;
}

Form::~Form() {
	std::cout << "Default constructor called. " << getName() << "Form " << "shredded" << std::endl;
}

Form &Form::operator=(const Form &other) {
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other) {
		_isSigned = other.getIsSigned();
	}
	return *this;
}

const std::string	&Form::getName() const {
	return _name;
}

bool				Form::getIsSigned() const {
	return _isSigned;
}

const int			Form::getGradeToSign() const {
	return _gradeToSign;
}

const int			Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void				Form::beSigned(Bureaucrat const &other) {
	if (other.getGrade() <= getGradeToSign())
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &b) {
	if (b.getIsSigned()) {
		return (out << b.getName() << " Form" << ":\nRequired grade to sign is " << b.getGradeToSign() \
            << "\nRequired grade to execute is " << b.getGradeToExecute() << "\nForm status: signed\n");
	}
	else
	{
		return (out << b.getName() << " Form" << ":\nRequired grade to sign is " << b.getGradeToSign() \
			<< "\nRequired grade to execute is " << b.getGradeToExecute() << "\nForm status: not signed\n");
	}
}