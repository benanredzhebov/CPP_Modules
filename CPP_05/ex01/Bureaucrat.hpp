/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:46:06 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/16 13:19:35 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(); 									// Canonical
		Bureaucrat(const std::string &name, int grade); // Canonical
		Bureaucrat(const Bureaucrat &other); 			// Canonical
		~Bureaucrat();
		
		Bureaucrat &operator=(const Bureaucrat &other); // Canonical

		/* Exception classes for handling invalid grades(error catching)*/

		// Thrown when the grade is too high! what() Method: Returns a C-string describing the error.
		class GradeTooHighException : public std::exception {
			const char* what() const throw() {
				return ": grade is too low!\n";
			}
		};

		// Thrown when the grade is too low!
		class GradeTooLowException : public std::exception {
			const char* what() const throw() {
				return ": grade is too high!\n";
			}
		};

		
		const std::string	&getName() const;
		int					getGrade() const;
	
		void				incrementGrade();
		void				decrementGrade();
	
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif