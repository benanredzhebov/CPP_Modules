/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:22:24 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/07 14:10:03 by beredzhe         ###   ########.fr       */
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
	// vec.erase(vec.begin()); // Slow, as all elements must be shifted

	std::list<int> lst; //Doubly linked list optimized for fast insertions/removals at any position.
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);
	// std::list<int>::iterator it = lst.begin();
	// std::advance(it, 2);
	// lst.insert(it, 10); // Fast insertion

	std::deque<int> deq; //Double-ended queue allowing fast insertions/removals at both ends.
	deq.push_back(15);
	deq.push_back(45);
	deq.push_back(65);
	deq.push_back(75);
	deq.push_back(95);
	// deq.push_front(0); // Fast, adds to the front
	// deq.push_back(5);  // Fast, adds to the end
	// int x = deq[2];    // Fast access
	// deq.pop_front();   // Fast, removes from the front

	try {
		std::cout << "VECTOR" << std::endl;

		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
			std::cout << *it << std::endl;
		}
		std::vector<int>::iterator vec_it = easyfind(vec, 5);
		std::cout << "Found in list: " << *vec_it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "LIST" << std::endl;

		for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
			std::cout << *it << std::endl;
		}
		std::list<int>::iterator lst_it = easyfind(lst, 20);
		std::cout << "Found in list: " << *lst_it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "DEQUE" << std::endl;
		
		for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++) {
			std::cout << *it << std::endl;
		}
		std::deque<int>::iterator deq_it = easyfind(deq, 95);
		std::cout << "Found in list: " << *deq_it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try {
		easyfind(vec, 6);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}


/*In summary:

std::vector is optimal for random access and is most efficient for end insertions.
std::list is optimal for frequent insertions and deletions at any position but lacks random access.
std::deque combines fast random access with efficient insertions and deletions at both ends.*/