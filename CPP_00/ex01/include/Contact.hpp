/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:03:39 by benanredzhe       #+#    #+#             */
/*   Updated: 2024/09/05 17:19:35 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CPP
#define CONTACT_CPP

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string _darkestSecret;
	
	public:
		Contact (void);
		~Contact (void);
		
		int		index;
		void	addEntry(int entry, std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		void	putName(void);
		void	putEntry(void);
};

#endif