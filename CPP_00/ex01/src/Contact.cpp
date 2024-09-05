/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:19:50 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/09/05 17:23:46 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
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

void Contact::putName(void)
{
	int user_index = this->index + 1;

	std::cout << "|";
	std::cout << std::setw(10) << user_index << "|";
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

void Contact::putEntry(void)
{
	std::cout << "" << std::endl;
	std::cout << "Contact" << std::endl;
	std::cout << "first name: " << this->_firstName << std::endl;
	std::cout << "last name: " << this->_lastName << std::endl;
	std::cout << "nickname: " << this->_nickName << std::endl;
	std::cout << "phone number: " << this->_phoneNumber << std::endl;
	std::cout << "secret: " << this->_darkestSecret << std::endl;
}