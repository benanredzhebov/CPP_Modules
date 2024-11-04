/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:06:59 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/04 15:10:26 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"

Span::Span() {
	std::cout << "Default constructor called" << std::endl;
} 

Span::Span(unsigned int N) {
	std::cout << "Parameterized constructor called" << std::endl;
}

