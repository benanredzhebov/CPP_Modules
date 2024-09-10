/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:56:09 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/10 11:16:51 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_entry = -1;
	this->oldest = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

int PhoneBook::getInfo(void)
{
	int i = 0;			 // iterate through input fields
	int j;				 // iterate through characters in the phone number
	std::string info[5]; // store user input

	while (i < 5)
	{
		if (i == 0)
			std::cout << "Enter first name: ";
		if (i == 1)
			std::cout << "Enter last name: ";
		if (i == 2)
			std::cout << "Enter nickname: ";
		if (i == 3)
			std::cout << "Enter phone number: ";
		if (i == 4)
			std::cout << "Enter darkest secret: ";
		std::getline(std::cin, info[i]);
		j = 0;
		while (i == 3 && info[i] != "" && std::isdigit(info[i][j]))
			j++;
		if (i == 3 && info[i] != "" && j != (int)info[i].length())
		{
			std::cout << "Phone number must contain only digits" << std::endl;
			info[i] = "";
		}
		if (info[i] == "" && std::cin.eof() == false)
			continue;
		else if (std::cin.eof() == true)
		{
			std::cout << "" << std::endl;
			std::cout << "Exiting phonebook... GOOD BYE" << std::endl;
			return (0);
		}
		else
			i++;
	}
	_putContact(info[0], info[1], info[2], info[3], info[4]);
	std::cout << "Contact saved" << std::endl;
	return (1);
}

/*function is responsible for storing a new contact in the phone book.
It manages adding contacts, and if the phone book is full, it replaces
the oldest contact with the new one.*/
void PhoneBook::_putContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	if (this->_entry < 7)
	{
		this->_entry++;
		contacts[_entry].addEntry(this->_entry, fn, ln, nn, pn, ds);
	}
	else
	{
		std::cout << "Oldest Contact is replaced by the new Contact" << std::endl;
		// _replaceOldestContact();
		contacts[this->oldest].addEntry(this->oldest, fn, ln, nn, pn, ds);
		contacts[this->oldest].index = this->oldest;
		if (this->oldest == 7)
			this->oldest = 0;
		else
			this->oldest++;
	}
}


// I imlement this inside of the _putContact.
// void PhoneBook::_replaceOldestContact(void)
// {
// 	// for (int i = 0; i < 7; i++)
// 	for (int i = 7; i > 0; --i)
// 	{
// 		this->contacts[i].index = i;
// 	}
// }

/*function allows the user to search for a contact by displaying a
list of contacts (in a summary format), then prompting the user to
select a contact by entering its index. If the index is valid, it
displays the detailed contact information.*/
int PhoneBook::searchEntries(void)
{
	if (_displayExtract())
	{
		std::cout << "Write index: ";
		std::getline(std::cin, _userInput);
		if (std::cin.eof() == true)
		{
			std::cout << "" << std::endl;
			std::cout << "Exiting phonebook... GOOD BYE" << std::endl;
			return (0);
		}
		while (!_displayData(_userInput))
		{
			if (std::cin.eof() == true)
			{
				std::cout << "" << std::endl;
				std::cout << "Exiting phonebook... GOOD BYE" << std::endl;
				exit(0);
			}
			std::cout << "Write index: ";
			std::getline(std::cin, _userInput);
			if (std::cin.eof() == true)
			{
				std::cout << "" << std::endl;
				std::cout << "Exiting phonebook... GOOD BYE" << std::endl;
				return (0);
			}
		}
	}
	return (1);
}

/*function is responsible for displaying a summary
of all contacts in the phonebook. If there are no contacts
in the phonebook, it displays a message informing the user that no
entries are available.*/
bool PhoneBook::_displayExtract(void)
{
	if (this->_entry >= 0)
	{
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		for (int i = 0; i <= this->_entry; i++)
			contacts[i].putName();
		return (true);
	}
	std::cout << "No entries found! enter ADD to add a contact." << std::endl;
	return (false);
}

/*The function checks if the user’s input is a single
character representing a valid contact index.
It converts the input to an integer and verifies whether
the index is valid (i.e., within the range of existing
contacts).
If the index is valid, it displays the detailed information
for the contact using putEntry().
If the input is invalid or out of range, the function
prints an error message and returns false.*/
bool PhoneBook::_displayData(std::string _user_input)
{
	int userIndex = -5;
	int index;

	if (_userInput.length() > 1)
	{
		std::cout << "No entry found! Write an existing index." << std::endl;
		return (false);
	}
	else
		userIndex = int(_user_input[0]) - 48;
	index = userIndex - 1;
	if (index >= 0 && index <= this->_entry)
		contacts[index].putEntry();
	else
	{
		std::cout << "No entry found! Write an existing index." << std::endl;
		return (false);
	}
	return (true);
}

void PhoneBook::showInstruction(void)
{
	std::cout << "Welcome!" << std::endl;
	std::cout << "This phonebook can store up to 8 contacts!" << std::endl;
	std::cout << "Use 'ADD' to add a contact" << std::endl;
	std::cout << "Use 'SEARCH' to search for a contact" << std::endl;
	std::cout << "Use 'EXIT' to leave the phonebook" << std::endl;
}