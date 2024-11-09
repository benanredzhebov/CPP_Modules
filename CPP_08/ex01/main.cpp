/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:36:01 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/07 15:08:14 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"

int	main() {
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Max size: " << sp.getMaxSize() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::vector<int> moreNumbers;
		moreNumbers.push_back(1);
		moreNumbers.push_back(2);
		moreNumbers.push_back(3);
		moreNumbers.push_back(4);
		moreNumbers.push_back(5);
		
		Span sp2 = Span(10);
		sp2.addNumbers(moreNumbers.begin(), moreNumbers.end());
		sp2.addNumbers(moreNumbers.begin(), moreNumbers.end());

		std::cout << "Max size: " << sp2.getMaxSize() << std::endl;
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
		
		Span sp3 = Span(10000);
		srand(time(0)); //random number gereneration

		std::vector<int> randomNumbers;
		for (int i = 0; i < 10000; ++i) {
			randomNumbers.push_back(rand());
		}

		sp3.addNumbers(randomNumbers.begin(), randomNumbers.end());

		std::cout << "Max size: " << sp3.getMaxSize() << std::endl;
		std::cout << "Shortest span (10,000 numbers): " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span (10,000 numbers): " << sp3.longestSpan() << std::endl;
		
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}