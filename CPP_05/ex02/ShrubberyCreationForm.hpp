/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:09:06 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/20 07:49:42 by benanredzhe      ###   ########.fr       */
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

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
		
		std::string		getTarget() const;
		virtual void	execute(Bureaucrat const &executor) const;
		void			executeForm() const;
		
};

#endif