/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:44:29 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/15 11:19:33 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}


PmergeMe::PmergeMe(const std::vector<std::string>& args) {
	_unsortedSequence = _parsearguments(args); // _parsearguments checks that each string is a positive integer and converts it to an int, storing the result in _unsortedSequence.
	_sortedVector = _unsortedSequence;
	_sortedDeque = std::deque<int>(_unsortedSequence.begin(), _unsortedSequence.end());
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_unsortedSequence = other._unsortedSequence;
		_sortedVector = other._sortedVector;
		_sortedDeque = other._sortedDeque;
	}
	return *this;
}

bool PmergeMe::_isValidInteger(const std::string& str) const {
	for (size_t i = 0; i < str.size(); ++i) {
		if (!isdigit(str[i])) return false;
	}
	return !str.empty() && str[0] != '0';
}

/*Converts the string arguments into integers and stores them in std::vector<int>*/
std::vector<int> PmergeMe::_parsearguments(const std::vector<std::string>& args) {
	std::vector<int> numbers;
	for (size_t i = 0; i < args.size(); ++i) {
		if (!_isValidInteger(args[i])) {
			throw std::invalid_argument("Error: All arguments must be positive integers.");
		}
		numbers.push_back(std::atoi(args[i].c_str()));
	}
	return numbers;
}

/*sorst a subarray(from left to right) in ascending order*/
void PmergeMe::_insertionSort(std::vector<int>& sequence, size_t left, size_t right) {
	for (size_t i = left + 1; i <= right; ++i) {
		int key = sequence[i]; // key is number of 1 indices
		size_t j = i; // 1
		while (j > left && sequence[j - 1] > key) {
			sequence[j] = sequence[j - 1];
			--j;
		}
		sequence[j] = key;
	}
}

void PmergeMe::_insertionSort(std::deque<int>& sequence, size_t left, size_t right) {
	for (size_t i = left + 1; i <= right; ++i) {
		int key = sequence[i];
		size_t j = i;
		while (j > left && sequence[j - 1] > key) {
			sequence[j] = sequence[j - 1];
			--j;
		}
		sequence[j] = key;
	}
}

/*It merges elements in sorted order, copying them back to the original sequence*/
void PmergeMe::_merge(std::vector<int>& sequence, size_t left, size_t mid, size_t right) {
	std::vector<int> temp; // empty vector to store the merget result
	size_t i = left, j = mid;

	while (i < mid && j < right) {
		if (sequence[i] <= sequence[j]) {
			temp.push_back(sequence[i]);
			++i;
		} else {
			temp.push_back(sequence[j]);
			++j;
		}
	}

	/*This loop appends any remaining elements from the left half*/
	while (i < mid) {
		temp.push_back(sequence[i]);
		++i;
	}

	/*This loop appends any remaining elements from the right half*/
	while (j < right) {
		temp.push_back(sequence[j]);
		++j;
	}

	/*Copy temp back to sequence*/
	std::copy(temp.begin(), temp.end(), sequence.begin() + left);
}

void PmergeMe::_merge(std::deque<int>& sequence, size_t left, size_t mid, size_t right) {
	std::deque<int> temp;
	size_t i = left, j = mid;

	while (i < mid && j < right) {
		if (sequence[i] <= sequence[j]) {
			temp.push_back(sequence[i]);
			++i;
		} else {
			temp.push_back(sequence[j]);
			++j;
		}
	}

	while (i < mid) {
		temp.push_back(sequence[i]);
		++i;
	}

	while (j < right) {
		temp.push_back(sequence[j]);
		++j;
	}

	std::copy(temp.begin(), temp.end(), sequence.begin() + left);
}

/* Ford-Johnson sorting algorithm */
void PmergeMe::_fordJohnsonSortVector(std::vector<int>& sequence) {
	size_t n = sequence.size();

	if (n <= 1) return;

	/*Pairwise Sorting
	call merges the two subarrays defined by the indices [i, mid) and [mid, end).*/
	for (size_t i = 0; i < n; i += 2) {
		if (i + 1 < n && sequence[i] > sequence[i + 1]) {
			std::swap(sequence[i], sequence[i + 1]);
		}
	}

	/*Iterative merging.Gradually merges pairs into larger and larger sorted subarrays */
	for (size_t step = 2; step < n; step *= 2) {
		for (size_t i = 0; i < n; i += step) {
			size_t mid = std::min(i + step / 2, n);
			size_t end = std::min(i + step, n);
			_merge(sequence, i, mid, end);
		}
	}
	// Insertion sort ensures that any remaining small disorder is corrected.
	_insertionSort(sequence, 0, n - 1);
}

void PmergeMe::_fordJohnsonSortDeque(std::deque<int>& sequence) {
	size_t n = sequence.size();

	if (n <= 1) return;

	for (size_t i = 0; i < n; i += 2) {
		if (i + 1 < n && sequence[i] > sequence[i + 1]) {
			std::swap(sequence[i], sequence[i + 1]);
		}
	}

	for (size_t step = 2; step < n; step *= 2) {
		for (size_t i = 0; i < n; i += step) {
			size_t mid = std::min(i + step / 2, n);
			size_t end = std::min(i + step, n);
			_merge(sequence, i, mid, end);
		}
	}

	_insertionSort(sequence, 0, n - 1);
}


double PmergeMe::sortWithVector() {
	clock_t start = clock();
	_fordJohnsonSortVector(_sortedVector);
	clock_t end = clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
	return duration;
	// std::cout << "Time to process with std::vector: " << duration << " us" << std::endl;
}

double PmergeMe::sortWithDeque() {
	clock_t start = clock();
	_fordJohnsonSortDeque(_sortedDeque);
	clock_t end = clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6; // converts time from seconds to microseconds
	return duration;
	// std::cout << "Time to process with std::deque: " << duration << " us" << std::endl;
}

void PmergeMe::displayBeforeAfter() const {
	std::cout << RED << "Before: " << RESET;
	for (size_t i = 0; i < _unsortedSequence.size(); ++i) {
		std::cout << _unsortedSequence[i] << " ";
	} 
	std::cout << std::endl;

	std::cout << GREEN << "After (std::vector): " << RESET;
	for (size_t i = 0; i < _sortedVector.size(); ++i) {
		std::cout << _sortedVector[i] << " ";
	}
	std::cout << std::endl;

	std::cout << GREEN << "After (std::deque): " << RESET;
	for (std::deque<int>::const_iterator it = _sortedDeque.begin(); it != _sortedDeque.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
