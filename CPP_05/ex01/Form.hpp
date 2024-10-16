/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:59:21 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/16 14:10:04 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "./Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool 				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form();
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		Form(const Form &other);
		~Form();
		
		Form &operator=(const Form &other);
		 
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
		const int			getGradeToSign() const;
		const int			getGradeToExecute() const;

		void				beSigned(Bureaucrat const &other);
};
std::ostream &operator<<(std::ostream &out, const Form &b);

#endif