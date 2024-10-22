/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:59:21 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/22 11:24:02 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "./Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool 				_isSigned; // A boolean indicating whether it is signed
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form();
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		Form(const Form &other);
		~Form();
		
		Form &operator=(const Form &other);
		
		/*Inheriting from std::exception allows GradeTooHighException to be used as an exception that
		can be thrown and caught.
		Polymorphism
		When you derive a class from a base class and override a method in the derived class, you often want to ensure that the correct method is called based on the actual type of the object, not the type of the pointer or reference to the object. This is known as polymorphism.

		Exception Handling
		In the context of exception handling, the what method is used to provide a description of the exception. By making the what method virtual, you ensure that the correct what method is called for the specific type of exception, even if you catch the exception as a reference to the base class std::exception.*/
		class	GradeTooHighException : public std::exception {
			virtual const char* what() const throw() {
				return ": grade is too low!\n";
			}
		};
		
		class	GradeTooLowException : public std::exception {
			virtual const char* what() const throw() {
				return ": grade is too high!\n";
			}
		};

		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(Bureaucrat const &other);
};
std::ostream &operator<<(std::ostream &out, const Form &b);

#endif