/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:15:07 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/26 14:28:32 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

Point::Point() : x(0), y(0) {
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float xValue, const float yValue) : x(xValue), y(yValue) {
	std::cout << "Parameterized constructor called" << std::endl;
}

Point::Point(const Point &other) : x(other.getX()), y(other.getY()) {
	std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &other) {
	 /*Since the members x and y are const, I can't actually reassign them,
    so I will handle this properly. Ideally, I would not use the
    assignment operator in this context.*/
	std::cout << "Assignment operator called" << std::endl;
	return *this;
}

Point::~Point() {
	std::cout << "Destructor called" << std::endl;
}

/* Getter for x */
Fixed Point::getX(void) const {
	return this->x;
}

/* Getter for Y */
Fixed Point::getY(void) const {
	return this->y;
}