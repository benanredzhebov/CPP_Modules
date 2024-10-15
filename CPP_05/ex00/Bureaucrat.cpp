/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:52:41 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/15 15:02:49 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Defaulf name") {
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat(const std::string name) : _name(name) {
	std::cout << "Bureaucrat constructor with name called" << std::endl;
}
