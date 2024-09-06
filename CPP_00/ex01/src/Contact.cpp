/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:19:50 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/09/06 12:36:16 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact(void)
{
	//std::cout << "Constructor called" << std::endl;
	return;
}

Contact::~Contact(void)
{
	//std::cout << "Destructor called" << std::endl;
	return;
}

void Contact::addEntry(int entry, std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	this->index = entry;
	this->_firstName = fn;
	this->_lastName = ln;
	this->_nickName = nn;
	this->_phoneNumber = pn;
	this->_darkestSecret = ds;
}

/* Function is responsible for displaying a summary of a Contact object’s
details in a formatted table. */
void Contact::putName(void)
{
	int user_index = this->index + 1;

	std::cout << "|"; //Begin of index
	std::cout << std::setw(10) << user_index << "|"; //End of index
	if (this->_firstName.length() > 10)
		std::cout << std::setw(10) << this->_firstName.substr(0, 9) + "." << "|";
	else
		std::cout << std::setw(10) << this->_firstName << "|";
	if (this->_lastName.length() > 10)
		std::cout << std::setw(10) << this->_lastName.substr(0, 9) + "." << "|";
	else
		std::cout << std::setw(10) << this->_lastName << "|";
	if (this->_nickName.length() > 10)
		std::cout << std::setw(10) << this->_nickName.substr(0, 9) + "." << "|" << std::endl;
	else
		std::cout << std::setw(10) << this->_nickName << "|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
}

/*Outout all the details of a contact in a readable format*/
void Contact::putEntry(void)
{
	std::cout << "" << std::endl; //putting empty string before print the contact details
	std::cout << "Contact" << std::endl;
	std::cout << "first name: " << this->_firstName << std::endl;
	std::cout << "last name: " << this->_lastName << std::endl;
	std::cout << "nickname: " << this->_nickName << std::endl;
	std::cout << "phone number: " << this->_phoneNumber << std::endl;
	std::cout << "secret: " << this->_darkestSecret << std::endl;
}