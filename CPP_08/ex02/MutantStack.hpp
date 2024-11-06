/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:25:33 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/06 13:23:28 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		~MutantStack();

		MutantStack &operator=(const MutantStack &other);

		typedef typename std::stack<T>::container_type::iterator		iterator; // This line creates an alias named iterator for the iterator type of the underlying container used by std::stack<T>.This allows me to use iterator as a type within the MutantStack class to iterate over the elements of the stack.
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator; // This line creates an alias named const_iterator for the constant iterator type of the underlying container used by std::stack<T>. This allows me to use const_iterator as a type within the MutantStack class to iterate over the elements of the stack in a read-only manner.

		iterator		begin();
		iterator		end();
		const_iterator	begin() const;
		const_iterator	end() const;
};

#include "MutantStack.tpp"

#endif