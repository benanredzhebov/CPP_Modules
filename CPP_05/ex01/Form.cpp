/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:59:21 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/19 08:54:44 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Form dflt constructor called." << getName() << " Form with sign grade " \
		<< getGradeToSign() << " and execution grade " << getGradeToExecute() << " is printid." << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
		std::cout << "Form parameterized constructor called." << std::endl;
		try {
			if (gradeToSign > 150 || gradeToExecute > 150)
				throw Form::GradeTooLowException();
			else if (gradeToSign < 1 || gradeToExecute < 1)
				throw Form::GradeTooHighException();
			else {
				std::cout << getName() << " Form with sign grade " \
					<< getGradeToSign() << " and execution grade " << getGradeToExecute() << " is printed." << std::endl;
			}
		}
		catch (const std::exception &ex) {
			std::cerr << "Exception thrown for " << getName() << " Form " << ex.what();
		}
	}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), \
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
		std::cout << "Form Copy constructor called." << getName() << " Form  with sign grade " \
				<< getGradeToSign() << " and execution grade " << getGradeToExecute() << " is photocopied" << std::endl;
	}
	
Form::~Form () {
	std::cout << "Form destructor called." << getName() << " Form " << "shredded" << std::endl;
}

Form &Form::operator=(const Form &other) {
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

int					Form::getGradeToSign() const {
	return _gradeToSign;
}

int					Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat const &other) {
	if (other.getGrade() <= getGradeToSign())
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &b) {
	if (b.getIsSigned()) {
		return (out << b.getName() << " Form" << "\nRequired grade to sign is " << b.getGradeToSign() \
			<<"\nRequired grade to execute is " << b.getGradeToExecute() << "\nForm status: signed\n");
	}
	else {
		return (out << b.getName() << " Form" << "\nRequired grade to sign is " << b.getGradeToSign() \
			<<"\nRequired grade to execute is " << b.getGradeToExecute() << "\nForm status: not signed\n");
	}
}