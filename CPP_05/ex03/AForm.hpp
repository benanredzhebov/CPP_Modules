/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:59:21 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/18 10:46:19 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool 				_isSigned; // A boolean indicating whether it is signed
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm();
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm &other);
		virtual ~AForm(); // When I have a base class with derived classes, it is important to have a virtual destructor in the base class to ensure that the destructors of the derived classes are called correctly when an object is deleted through a base class pointer.
		
		AForm &operator=(const AForm &other);
		
		/*Inheriting from std::exception allows GradeTooHighException to be used as an exception that
		can be thrown and caught.*/
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

		class	FormNotSignedException: public std::exception {
			virtual const char* what() const throw() {
				return "the form is not signed and cannot be executed.\n";
			}
		};

		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(Bureaucrat const &other);
		
		
		virtual void		execute(Bureaucrat const &executor) const = 0;
};
std::ostream &operator<<(std::ostream &out, const AForm &b);

#endif