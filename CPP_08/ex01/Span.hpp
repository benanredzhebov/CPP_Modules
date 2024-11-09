/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:57:37 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/07 15:08:43 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class Span {
	private:
		std::vector<int>	_numbers;
		unsigned int		_maxSize;
		
		class SpanFullException : public std::exception {
			const char* what() const throw() {
				return "Span is full. Cannot add more numbers.";
			}
		};

		class NotEnoughNumbersException : public std::exception {
			const char* what() const throw() {
				return "Not enough numbers to find a span.";
		}
	};
	
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		~Span();
		
		Span &operator=(const Span &other);

		void	addNumber(int number);
		
		template <typename Iterator> // Iterator is a place holder for any iterator type.(iterators for vectors,lists...)
		void	addNumbers(Iterator begin, Iterator end) {
			// std::cout << "Adding numbers from range: ";
			// for (Iterator it = begin; it !=end; ++it) {
			// 	std::cout << *it << " ";
			// }
			// std::cout << std::endl;

			std::cout << "Current size of  _numbers: " << _numbers.size() << std::endl;
			std::cout << "Number of elements to add: " << std::distance(begin, end) << std::endl;
			// Calculates the number of elements in the range[begin, end].The sum of these two values represents the total number of elements that would be in _numbers after adding the new elements
			if (std::distance(begin, end) + _numbers.size() > _maxSize) {
				throw SpanFullException();
			}
			_numbers.insert(_numbers.end(), begin, end); // inserts the elements in the range [begin, end) into the _numbers container. The elements are inserted at the end of the _numbers container.
		
			std::cout << "New size of _numbers: " << _numbers.size() << std::endl;
		}
		
		int			shortestSpan() const;
		int			longestSpan() const;
		unsigned	getMaxSize() const;
};

#endif