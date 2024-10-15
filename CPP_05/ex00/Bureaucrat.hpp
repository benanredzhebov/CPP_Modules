/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:46:06 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/15 15:22:33 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private:
		const std::string	_name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		
		Bureaucrat &operator=(const Bureaucrat &other);

		class GradeToHihtException : public std::exception {
			const char* what() const throw() {
				return "Grade too high!";
			};

		class GradeTooLowException : public std::exception {
			const char* what() const throw() {
				return "Grade too low!";
			}
		};

		
		std::string	getName();
		std::string	getType();
	
		void	increment() const;
		void	decrement() const;
	
};

#endif