/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filehandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 08:20:19 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/14 08:49:30 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEHANDLER_HPP
# define FILEHANDLER_HPP

#include <iostream>
#include <fstream>
#include <string>

class Filehandler {
	private:
		std::string	_fileName;
		void	_replaceloop(std::ifstream &infile, std::ofstream &outfile,
			std::string s1, std::string s2);
	
	public:
	Filehandler(std::string fileName);
	~Filehandler();

	std::string getName() const;
	void	replace(std::string s1, std::string s2);
};

#endif