/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:45:48 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/04 11:59:01 by beredzhe         ###   ########.fr       */
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

class NotFound : public std::exception {
	virtual const char *what() const throw() {
		return "Value not found in container";
	}
};

/* Container by referrence, value I'am searching for it in the container */
template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw NotFound();
	}
	return it;
}

#endif