/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:09:06 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/18 10:49:58 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "./AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm(); // Prevents resource leaks and undefined behavior when dealing with polymorphic objects.

		ShrubberyCreationForm		&operator=(const ShrubberyCreationForm &other);
		std::string		getTarget() const;

		virtual void	execute(Bureaucrat const &executor) const;
		void	executeForm() const;
		
};

#endif