/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:45:48 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/07 09:13:10 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND
#define EASYFIND

#include <algorithm>
# include <iterator>
# include <stdexcept>
# include <iostream>
# include <list>
# include <deque>
# include <vector>

class EasyFind {
	public:
		EasyFind() {}
		EasyFind(const EasyFind &other) {
			*this = other;
		}
		~EasyFind() {}

		EasyFind &operator=(const EasyFind &other) {
			(void)other;
			return *this;
		}
};

class NotFound : public std::exception {
	virtual const char *what() const throw() {
		return "Value not found in container";
	}
};

/* Container by referrence.Search for a specific value in a container
std::find is a standard algorithm that searches for value in the range [container.begin(), container.end()). */
template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw NotFound();
	}
	return it;
}

#endif