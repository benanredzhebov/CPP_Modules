/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:47:16 by beredzhe          #+#    #+#             */
/*   Updated: 2024/11/11 14:05:57 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << "input_file" << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	if (!btc.loadDatabase(argv[1])) {
		return 1;
	}
	
	btc.processInput(argv[2]);
	return 0;
}