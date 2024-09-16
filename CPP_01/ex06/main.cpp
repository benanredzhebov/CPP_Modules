/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:26:17 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/16 13:32:31 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << "<log level>" << std::endl;
		return 1;
	}

	Harl harl;
	harl.complain(av[1]);

	return 0;
}