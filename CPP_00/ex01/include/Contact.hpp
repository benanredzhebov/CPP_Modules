/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:03:39 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/09/10 09:50:40 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream> // standart input-output stream library
#include <iomanip> // library for input-output manipulators (setting width)

/*Class definition*/
class Contact
{
	private:
		std::string	_firstName; // Stores the first name of the contact
		std::string	_lastName; // Stores the last name of the contact
		std::string	_nickName; // Stores the nickname of the contact
		std::string	_phoneNumber; // Stores the phone number of the contact
		std::string _darkestSecret; // Stores the darkest secret of the contact
	
	public:
		Contact (); // Constructor declaration
		~Contact (); // Destructor declaration
		
		int		index; // Public integer to store the index of the contact
		void	addEntry(int entry, std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		void	putName(void); // Method to print the name of the contact
		void	putEntry(void);
};

#endif