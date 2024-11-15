/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:32:15 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/14 14:12:40 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>

class Rpn {
	private:
		bool	_isOperator(const std::string &token);
		int		_applyOperator(const std::string &op, int a, int b);
		
	public:
		Rpn();
		Rpn(const Rpn &other);
		~Rpn();

		Rpn	&operator=(const Rpn &other);

		int	evaluate(const std:: string &expression);
	
};

class RpnException : public std::exception {
private:
	std::string message;

public:
	explicit RpnException(const std::string& msg) : message(msg) {}

	// Override what() to return the error message
	const char* what() const throw() {
		return message.c_str();
	}
	virtual ~RpnException() throw() {}
};

#endif
