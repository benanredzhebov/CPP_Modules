/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:06:59 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/05 14:03:49 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"

Span::Span() : _maxSize(0) {
	std::cout << "Default constructor called" << std::endl;
} 

Span::Span(unsigned int N) : _maxSize(N) {
	std::cout << "Parameterized constructor called" << std::endl;
}

Span::Span(const Span &other) : _numbers(other._numbers), _maxSize(other._maxSize) {
	std::cout << "Copy constructor called" << std::endl;
}

Span::~Span() {
	std::cout << "Default destructor called" << std::endl;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_numbers = other._numbers;
		_maxSize = other._maxSize;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

void Span::addNumber(int number) {
	if (_numbers.size() >= _maxSize) {
		throw SpanFullException();
	}
	_numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw NotEnoughNumbersException();
	}
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end()); //Sorting is crucial because the shortest difference between two numbers will always be between two consecutive numbers in a sorted list.
	int shortest = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 1; i < sortedNumbers.size() - 1; ++i) {
		int span = sortedNumbers[i + 1] - sortedNumbers[i];
		if (span < shortest) {
			shortest = span;
		}
	}
	return shortest;
}

int Span::longestSpan() const {
	if (_numbers.size() < 2) {
		throw NotEnoughNumbersException();
	}
	int	min = *std::min_element(_numbers.begin(), _numbers.end());
	int	max = *std::max_element(_numbers.begin(), _numbers.end());
	return max - min;
}

unsigned int Span::getMaxSize() const {
	return _maxSize;
}