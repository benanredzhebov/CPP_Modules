/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:38:12 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/18 11:48:38 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"


class Intern {
	public:
		Intern();
		Intern(const Intern &other);
		virtual ~Intern();

		Intern &operator=(const Intern &other);

		AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif