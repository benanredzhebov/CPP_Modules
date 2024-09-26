/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:41:12 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/26 14:52:29 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(0.0f, 5.0f);
	Point p(2.0f, 2.0f);

	if (bsp(a, b, c, p))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;

	return 0;
}