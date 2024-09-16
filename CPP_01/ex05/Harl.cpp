/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:14:08 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/16 11:07:51 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"


Harl::Harl() {}

Harl::~Harl() {}

/*Private member functions.*/
void	Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/*Public function to map the complaint level to the corresponding function.*/
void	Harl::complain(std::string level) {
	/*Array of pointers to member functions*/
	void (Harl::*complaints[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	/*Array of corresponding strings for levels*/
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	/*Iterate and compare the levels*/
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*complaints[i])();
			return ;
		}
	}
	std::cout << "" << std::endl;
	std::cout << "Unknown complaint level: " << level << std::endl;
}