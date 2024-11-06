/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:21:35 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/06 13:23:30 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() {
	std::cout << "Default constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other) {
	std::cout << "Copy assignment operators called" << std::endl;
}

template<typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "Default destructor called" << std::endl;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other) {
	if (this != &other) {
		std::stack<T>::operator=(other);
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return std::stack<T>::c.end();
}