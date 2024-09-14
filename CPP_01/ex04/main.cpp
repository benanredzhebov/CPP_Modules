/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:38:28 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/14 09:44:53 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Filehandler.hpp"

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Usage " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	if (s1.empty()) {
		std::cerr << "Error: s1 cannot be an empty string" << std::endl;
		return 1;
	}
	Filehandler fileHandler(filename);
	fileHandler.replace(s1, s2);

	return 0;
}