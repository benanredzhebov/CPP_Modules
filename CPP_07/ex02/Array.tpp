/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:09:19 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/29 09:58:12 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "./Array.hpp"

template <typename T>

Array<T>::Array() : _elements(NULL), _length(0) {
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]), _length(n) {
	std::cout << "Parameterized constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &other) : _elements(new T[other._length]), _length(other._length) {
	std::cout << "Copy constructor called" << std::endl;
	for (unsigned int i = 0; i < this->_length; ++i) {
		this->_elements[i] = other._elements[i];
	}
}

template <typename T>
Array<T>::~Array() {
	std::cout << "Default destructor called" << std::endl;
	delete[] _elements;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (*this != other) {
		delete[] this->_elements;
		this->_length = other.length;
		this->_elements = new T[_length];
		for (unsigned int i = 0; i < this->_length; ++i) {
			this->_elements[i] = other._elements[i];
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= this->_length)
		throw std::out_of_range("Index out of bounds");
	return this->_elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= this->_length)
		throw std::out_of_range("Index out of bounds");
	return this->_elements[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->_length;
}

template <typename T>
void Array<T>::print() {
	for (unsigned int i = 0; i < this->_length; i++) {
		std::cout << this->_elements[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw() {
	return ("Index out of range");
}

#endif