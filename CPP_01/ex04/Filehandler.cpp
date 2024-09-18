/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filehandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 08:34:17 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/18 11:36:42 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filehandler.hpp"

Filehandler::Filehandler(std::string fileName) : _fileName(fileName) {}

Filehandler::~Filehandler() {
	std::cout << "Filehandler for " <<_fileName << " destroyed." << std::endl;
}

/* Getter for the file name */
std::string Filehandler::getName() const {
	return _fileName;
}

/* Internal function to replace all occurrences of s1 with s2
in each line*/
void	Filehandler::_replaceloop(std::ifstream &infile, std::ofstream &outfile,
			std::string s1, std::string s2) {
				std::string	line;
				size_t		pos;
				
				while (std::getline(infile, line)) {
					while ((pos = line.find(s1)) != std::string::npos) {
						line.erase(pos, s1.length());
						line.insert(pos, s2);
					}
					outfile << line << std::endl;
				}
			}
/*Public method to open the files and start the replacement
c_ctr - converting the string to a C-style string(to const *char)*/
void	Filehandler::replace(std::string s1, std::string s2) {
	std::ifstream infile(_fileName.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: Could not open the file " << _fileName << std::endl;
		return ;
	}

	if (infile.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "File is empty" << std::endl;
		return ;
	}
	
	std::ofstream outfile((_fileName + ".replace").c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: Could not create output file " <<_fileName << std::endl;
		infile.close();
		return ;
	}

	_replaceloop(infile, outfile, s1, s2);

	/* Close the files */
	infile.close();
	outfile.close();
	
	std::cout << "File has been processed successfully and saved as " << _fileName << ".replace" << std::endl;
}