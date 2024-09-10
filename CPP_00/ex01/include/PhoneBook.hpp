/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:26:39 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/09/10 11:17:07 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include "./Contact.hpp"

class PhoneBook
{
	/*These members are private because they are internal details of the PhoneBook
	lass and should not be accessible directly from outside the class.*/
	private:
		Contact		contacts[8]; // Objects to store the contacts
		std::string	_userInput; // A string to store user input
		int			_entry; // tracking how many contacts have been added to the phonebook
		void		_putContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		// void		_replaceOldestContact(); // A private method to replace the oldest contact in the phonebook
		bool		_displayExtract(void); // A private method to displat a summary of the contacts
		bool		_displayData(std::string user_input);
		int			oldest;
		
	/*These members are public because they define the interface through which users of
	the PhoneBook class can interact with it.*/
	public:
		PhoneBook(void);
		~PhoneBook(void);

		int		getInfo(void); // A public method to get information from the user
		int		searchEntries(void); // A public method to search for entries in the phonebook
		void	showInstruction(void); // A public method to show instructions to the user
};

#endif