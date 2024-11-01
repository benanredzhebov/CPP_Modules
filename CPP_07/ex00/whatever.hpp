/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:10:41 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/01 08:11:43 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T &a, const T &b) {
	return (a < b) ? a : b; // if a is less than b return a.
}

template <typename T>
T max(T &a, const T &b) {
	return (a > b) ? a : b;
}

#endif



/*Templates allow us to write generic code that can work with different
types without specyfing the exact data type in advance.
We can use "T" as a placeholder for any type.*/