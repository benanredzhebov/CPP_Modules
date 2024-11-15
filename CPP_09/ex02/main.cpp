/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:17:31 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/15 11:25:47 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error: Please provide a sequence of positive integers." << std::endl;
		return 1;
	}

	try {
		std::vector<std::string> args(argv + 1, argv + argc);
		PmergeMe sorter(args);
		sorter.sortWithVector();
		sorter.sortWithDeque();
		sorter.displayBeforeAfter();
		std::cout << std::endl <<  YELLOW << "Time to process a range of " <<  argc - 1 <<  " elements with std::vector : " << std::fixed << std::setprecision(2) << sorter.sortWithVector() << " us" << std::endl;
		std::cout << "Time to process a range of " <<  argc - 1 <<  " elements with std::deque :  " << std::fixed << std::setprecision(2) << sorter.sortWithDeque() << " us" << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}


