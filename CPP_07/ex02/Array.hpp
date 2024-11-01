/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:55:22 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/01 09:24:04 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
	private:
	T*				_array;
	unsigned int	_length;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();
		
		Array& operator=(const Array &other);
		T& operator[](unsigned int index); // Allow access to elements of the array  using the subscript operator[]

		unsigned int	size() const; // Returns the number of elements in the array
		void			print(void); // Prints the elements of the array
		
		class OutOfRangeException : public std::exception{
			public:
				virtual const char * what() const throw();
		};
};

#include "./Array.tpp" // By including the .tpp file at the end of the header file, you ensure that the definitions are available wherever the header is included.

#endif