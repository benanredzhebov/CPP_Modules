/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:24:06 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/26 14:59:06 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int value) {
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << _fractionalBits; // Convert it to fixed points
}

Fixed::Fixed(const float value) {
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

/* Copy assignment operator */
Fixed &Fixed::operator=(const Fixed &other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();
	return *this;
}

/* Getters and Setters */
int		Fixed::getRawBits(void) const {
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

/*Conversion functions */
float	Fixed::toFloat(void) const {
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int		Fixed::toInt(void) const {
	return this->_fixedPointValue >> _fractionalBits; 
}

/* Comparison operators */
bool	Fixed::operator>(const Fixed &other) const {
	return this->_fixedPointValue > other.getRawBits();
}

bool	Fixed::operator<(const Fixed &other) const {
	return this->_fixedPointValue < other.getRawBits();
}

bool	Fixed::operator>=(const Fixed &other) const {
	return this->_fixedPointValue >= other.getRawBits();
}

bool	Fixed::operator<=(const Fixed &other) const {
	return this->_fixedPointValue <= other.getRawBits();
}

bool	Fixed::operator==(const Fixed &other) const {
	return this->_fixedPointValue == other.getRawBits();
}

bool	Fixed::operator!=(const Fixed &other) const {
		return this->_fixedPointValue != other.getRawBits();
}

/* Arithmetic Operators */

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_fixedPointValue + other.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_fixedPointValue - other.getRawBits());
	return result;
}

Fixed	Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.setRawBits((this->_fixedPointValue * other.getRawBits()) >>_fractionalBits);
	return result;
}

Fixed	Fixed::operator/(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_fixedPointValue / other.getRawBits());
	return result;
}

/* Increment/ Decrement Operators */
Fixed &Fixed::operator++() {
	this->_fixedPointValue += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->_fixedPointValue += 1;
	return temp;
}

Fixed &Fixed::operator--() {
	this->_fixedPointValue -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->_fixedPointValue -= 1;
	return temp;
}

/* Min/ Max static functions */
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	return ( a > b) ? a : b;
}

Fixed Fixed::abs() const {
	Fixed result;
	result.setRawBits(std::abs(this->_fixedPointValue));
	return result;
}

/* Stream insertion operator overload */
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}


