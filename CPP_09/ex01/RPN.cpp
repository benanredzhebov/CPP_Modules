/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:46:17 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/12 14:07:12 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RPN.hpp"

Rpn::Rpn() {}
Rpn::Rpn(const Rpn &other) {
	*this = other;
}
Rpn::~Rpn() {}

Rpn &Rpn::operator=(const Rpn &other) {
	return *this;
}

bool Rpn::isOperator(const std::string &token) {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int Rpn::applyOperator(const std::string &op, int a, int b) {
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/") {
		if (b == 0) {
			std::cerr << "Error: division bt zero" << std::endl;
			exit(EXIT_FAILURE);
		}
		return a / b;
	}
	std::cerr << "Error: unknown operator" << op << std::endl;
	exit(EXIT_FAILURE);
}

int Rpn::evaluate(const std:: string &expression) {
	std::istringstream iss(expression);
	std::stack<int> stack;
	std::string token;

	while (iss >> token) {
		if (isOperator(token)) {
			if (stack.size() < 2) {
				std::cerr << "Error: invalid expression" << std::endl;
				exit(EXIT_FAILURE);
			}
			int	b = stack.top(); stack.pop();
			int	a = stack.top(); stack.pop();
			int	result = applyOperator(token, a, b);
			stack.push(result);
		}
		else {
			int	number;
			try {
				number = std::stoi(token);
			} catch (const std::exception &e) {
				std::cerr << "Error: invalid token " << token << std::endl;
				exit (EXIT_FAILURE);
			}
			stack.push(number);
		}
	}
	if (stack.size() != 1) {
		std::cerr << "Error: invalid expression" << std::endl;
		exit(EXIT_FAILURE);
	}
	return stack.top();
}