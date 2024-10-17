/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:09:06 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/17 14:44:06 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include "./AForm.hpp"

class Shrubbery : public AForm {
	private:
		std::string	_target;

	public:
		Shrubbery();
		Shrubbery(const std::string &target);
		Shrubbery(const Shrubbery &other);
		virtual ~Shrubbery(); // Prevents resource leaks and undefined behavior when dealing with polymorphic objects.

		Shrubbery		&operator=(const Shrubbery &other);
		std::string		getTarget() const;

		void	execute(Bureaucrat const &executor) const;
		void	executeForm() const;
		
};

#endif