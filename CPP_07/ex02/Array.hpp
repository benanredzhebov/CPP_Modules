/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:55:22 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/29 21:45:23 by benanredzhe      ###   ########.fr       */
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
		T& operator[](unsigned int index);

		unsigned int	size() const;
		void			print(void);
		
		class OutOfRangeException : public std::exception{
			public:
				virtual const char * what() const throw();
		};
};

#include "./Array.tpp"

#endif
