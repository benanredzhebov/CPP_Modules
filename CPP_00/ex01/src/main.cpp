/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:25:50 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/09/08 11:44:41 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command; /*A string variable command is declared to hold user inputs*/

	phonebook.showInstruction();
	while (true)
	{
		std::cout << "Enter command: ";
		if (std::cin.eof() == true)
		{
			std::cout << "" << std::endl;
			std::cout << "Exiting phonebook... GOOD BYE" << std::endl;
			break;
		}
		std::getline(std::cin, command);
		if (command == "EXIT")
		{
			std::cout << "Exiting phonebook... GOOD BYE" << std::endl;
			break;
		}
		else if (command == "ADD")
		{
			if (!phonebook.getInfo())
				break;
		}
		else if (command == "SEARCH")
		{
			if (!phonebook.searchEntries())
				break;
		}
	}
	return (0);
}