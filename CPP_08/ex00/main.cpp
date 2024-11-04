/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:22:24 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/04 14:36:10 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main() {
	std::vector<int> vec; //Dynamic array that supports fast random access.
	vec.push_back(1); // add an element at the end of the list
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::list<int> lst; //Doubly linked list optimized for fast insertions/removals at any position.
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	std::deque<int> deq; //Double-ended queue allowing fast insertions/removals at both ends.
	deq.push_back(15);
	deq.push_back(45);
	deq.push_back(65);
	deq.push_back(75);
	deq.push_back(95);

	try {
		std::vector<int>::iterator vec_it = easyfind(vec, 5);
		std::cout << "Found in list: " << *vec_it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator lst_it = easyfind(lst, 20);
		std::cout << "Found in list: " << *lst_it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::deque<int>::iterator deq_it = easyfind(deq, 95);
		std::cout << "Found in list: " << *deq_it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		easyfind(vec, 6);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
