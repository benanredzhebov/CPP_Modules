/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:40:02 by beredzhe          #+#    #+#             */
/*   Updated: 2024/09/05 16:55:18 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int main(){
    Sample instance; // variable name instance. Will call the class Simple
    
    instance.foo = 42;
    std::cout << "instance.foo: " << instance.foo << std::endl;

    instance.bar();
    
    return 0;
}
