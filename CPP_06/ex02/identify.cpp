/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:52:33 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/27 18:26:48 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "/"<< p << "/" << "Pointer of type: A" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "/" << p << "/" << "Pointer of type: B" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "/" << p << "/" << "Pointer of type: C" << std::endl;
	}
	else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base& p) {
	bool	identified = false;
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "/"<< &p << "/" "Reference of type: A" << std::endl;
		identified = true;
	} catch (...) {}
	if (!identified) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "/"<< &p << "/" "Reference of type: B" << std::endl;
			identified = true;
		} catch (...) {}
	}
	
	if (!identified) {
		try {
			(void)dynamic_cast<C&>(p);
			std::cout << "/"<< &p << "/" "Reference of type: C" << std::endl;
			identified = true;
		} catch (...){}
	}
	if (!identified) {
		std::cout << "Unknown type" << std::endl;
	}
}