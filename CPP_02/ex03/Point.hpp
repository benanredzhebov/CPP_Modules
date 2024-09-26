/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:05:33 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/26 14:14:58 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "./Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point();

		/* Getter methods to access the coordinates */
		Fixed getX(void) const;
		Fixed getY(void) const;
};

#endif