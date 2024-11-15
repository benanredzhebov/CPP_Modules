/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:55:36 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/15 11:25:29 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <ctime>
#include <cstdlib> // for std::atoi
#include <iomanip>

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

class PmergeMe {
private:
	std::vector<int> _unsortedSequence;
	std::vector<int> _sortedVector;
	std::deque<int> _sortedDeque;

	bool _isValidInteger(const std::string& str) const;
	std::vector<int> _parsearguments(const std::vector<std::string>& args);

	void _insertionSort(std::vector<int>& sequence, size_t left, size_t right);
	void _insertionSort(std::deque<int>& sequence, size_t left, size_t right);

	void _merge(std::vector<int>& sequence, size_t left, size_t mid, size_t right);
	void _merge(std::deque<int>& sequence, size_t left, size_t mid, size_t right);

	void _fordJohnsonSortVector(std::vector<int>& sequence);
	void _fordJohnsonSortDeque(std::deque<int>& sequence);

public:
	PmergeMe();
	PmergeMe(const std::vector<std::string>& args); //if use explicit -> This can help prevent bugs where a std::vector<std::string> is accidentally passed to a function expecting a PmergeMe object.
	PmergeMe(const PmergeMe& other);
	~PmergeMe();

	PmergeMe& operator=(const PmergeMe& other);

	double	sortWithVector();
	double	sortWithDeque();
	void	displayBeforeAfter() const;
};

#endif // PMERGEME_HPP
