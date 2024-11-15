/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:46:17 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/14 17:20:18 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RPN.hpp"
#include <vector>

Rpn::Rpn() {}
Rpn::Rpn(const Rpn &other) {
	*this = other;
}
Rpn::~Rpn() {}

Rpn &Rpn::operator=(const Rpn &other) {
	(void)other;
	return *this;
}

// Helper function to print the contents of the stack
// void printStack(std::stack<int> stack) {
// 	std::vector<int> elements;
// 	while (!stack.empty()) {
// 		elements.push_back(stack.top());
// 		stack.pop();
// 	}
// 	std::cout << "Stack contents: ";
// 	for (std::vector<int>::reverse_iterator it = elements.rbegin(); it != elements.rend(); ++it) {
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// }

bool	Rpn::_isOperator(const std::string &token) {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int		Rpn::_applyOperator(const std::string &op, int a, int b) {
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/") {
		if (b == 0) {
			throw RpnException("division by zero");
		}
		return a / b;
	}
	throw RpnException("unknown operator: " + op);
}

int Rpn::evaluate(const std:: string &expression) {
	std::istringstream iss(expression);
	std::stack<int> stack; // to store operands
	std::string token; // store each token (numbers or operators) read from the expression

	/*Iterates through each token in the expression*/
	while (iss >> token) {
		// std::cout << "Token: " << token << std::endl;
		if (_isOperator(token)) {
			// std::cout << "stack: " << stack.size() << std::endl;
			if (stack.size() < 2) {
				throw RpnException("invalid expression");
			}
			int	b = stack.top();
			// std::cout << "Top of stack b: " << stack.top() << std::endl;
			stack.pop();
			// printStack(stack);
			int	a = stack.top();
			// std::cout << "Top of stack a: " << stack.top() << std::endl;
			stack.pop();
			int	result = _applyOperator(token, a, b);
			stack.push(result);
		}
		else {
			int	number = std::atoi(token.c_str());
			stack.push(number);
		}
		// printStack(stack);
	}
	if (stack.size() != 1) {
		throw RpnException("invalid expression");
	}
	return stack.top();
}