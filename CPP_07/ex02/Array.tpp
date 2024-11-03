/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:09:19 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/03 08:19:59 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "./Array.hpp"

template <typename T>

Array<T>::Array() : _array(NULL), _length(0) {
	for (unsigned int i = 0; i < _length; ++i) {
		_array[i] = T(); // Initialize each element to the default value of T
	}
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _length(n) {
	std::cout << "Parameterized constructor called" << std::endl;
	for (unsigned int i = 0; i < _length; ++i) {
		_array[i] = T();
	}
}

template <typename T>
Array<T>::Array(const Array &other) : _array(new T[other._length]), _length(other._length) {
	std::cout << "Copy constructor called" << std::endl;
	for (unsigned int i = 0; i < this->_length; i++) {
		this->_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>::~Array() {
	std::cout << "Default destructor called" << std::endl;
	delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		delete[] _array;
		this->_length = other.size();
		this->_array = new T[_length];
		for (unsigned int i = 0; i < _length; ++i) {
			this->_array[i] = other._array[i];
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= this->_length)
		throw OutOfRangeException();
	return this->_array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->_length;
}

template <typename T>
void Array<T>::print() {
	for (unsigned int i = 0; i < _length; i++) {
		std::cout << _array[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw()
{
	return ("Index out of range");
}

#endif