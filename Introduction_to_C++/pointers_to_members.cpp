/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers_to_members.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benanredzhebov <benanredzhebov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:34:43 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/10 22:03:45 by benanredzhe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void ) : foo(0) {
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