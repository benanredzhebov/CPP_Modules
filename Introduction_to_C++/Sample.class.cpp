/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:34:43 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/03 17:53:01 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void ) {
    std::cout << "Constructor called" << std::endl;
    return;
}

Sample::~Sample( void ) {
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Sample::bar ( void ) {
    std::cout << "Member function bar called" << std::endl;
    return;
}