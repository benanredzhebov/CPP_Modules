/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:57:37 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/04 15:06:21 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span {
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &other);

		Span &operator=(const Span &other);

		void	addNumber();
		void	shortestSpan();
		void	longestSpan();
};

#endif