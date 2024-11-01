/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:44:02 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/11/01 08:19:35 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*func)(const T &)) {
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}

template <typename T>
void	print(const T &x) {
	std::cout << x << " ";
}

#endif