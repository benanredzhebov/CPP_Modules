/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:32:15 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/12 14:00:07 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

class Rpn {
	private:
		bool isOperator(const std::string &token);
		int applyOperator(const std::string &op, int a, int b);
		
	public:
		Rpn();
		Rpn(const Rpn &other);
		~Rpn();

		Rpn &operator=(const Rpn &other);

		int	evaluate(const std:: string &expression);
	
};

#endif
