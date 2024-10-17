/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:59:21 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/17 14:04:49 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Dflt constructor called." << getName() << " Form with sign grade " \
		<< getGradeToSign() << " and execution grade " << getGradeToExecute() << " is printid." << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
		std::cout << "Form parametrized constructor called." << std::endl;
		try {
			if (gradeToSign > 150 || gradeToExecute > 150)
				throw AForm::GradeTooLowException();
			else if (gradeToSign < 1 || gradeToExecute < 1)
				throw AForm::GradeTooHighException();
			else {
				std::cout << getName() << " Form with sign grade " \
					<< getGradeToSign() << " and execution grade " << getGradeToExecute() << " is printed." << std::endl;
			}
		}
		catch (const std::exception &ex) {
			std::cerr << "Exception thrown for " << getName() << " Form " << ex.what();
		}
	}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), \
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
		std::cout << "Form Copy constructor called." << getName() << " Form  with sign grade " \
				<< getGradeToSign() << " and execution grade " << getGradeToExecute() << " is photocopied" << std::endl;
	}
	
AForm::~AForm () {
	std::cout << "Form destructor called." << getName() << " Form " << "shredded" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		_isSigned = other.getIsSigned();
	}
	return *this;
}

const std::string	&AForm::getName() const {
	return _name;
}

bool				AForm::getIsSigned() const {
	return _isSigned;
}

int					AForm::getGradeToSign() const {
	return _gradeToSign;
}

int					AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &other) {
	if (other.getGrade() <= getGradeToSign())
		_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &b) {
	if (b.getIsSigned()) {
		return (out << b.getName() << " Form" << "\nRequired grade to sign is " << b.getGradeToSign() \
			<<"\nRequired grade to execute is " << b.getGradeToExecute() << "\nForm status: signed\n");
	}
	else {
		return (out << b.getName() << " Form" << "\nRequired grade to sign is " << b.getGradeToSign() \
			<<"\nRequired grade to execute is " << b.getGradeToExecute() << "\nForm status: not signed\n");
	}
}