/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:29:27 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/26 14:57:12 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"
#include "./Fixed.hpp"

/* Helper function to calculate the area of a triangle*/
Fixed area(Point const &p1, Point const &p2, Point const &p3)
{
	return Fixed(0.5f) * (p1.getX() * (p2.getY() - p3.getY()) +
						  p2.getX() * (p3.getY() - p1.getY()) +
						  p3.getX() * (p1.getY() - p2.getY())).abs();
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	/* Calculate the full area of the triangle ABC */
	Fixed A = area(a, b, c);

	/* Calculate the area of triangles formed with the point */
	Fixed A1 = area(point, b, c); // Point with BC
	Fixed A2 = area(a, point, c); // Point with AC
	Fixed A3 = area(a, b, point); // Point with AB

	// Check if point is inside the triangle
	// If the sum of A1, A2, and A3 is equal to A, point is inside
	return (A == (A1 + A2 + A3)) && A1 != Fixed(0) && A2 != Fixed(0) && A3 != Fixed(0);
}