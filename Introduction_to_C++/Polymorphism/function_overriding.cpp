/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_overriding.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:21:53 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/08 16:31:33 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The function of base class gets a new definition in
child the class and when we call the function of the child 
class using the object of child class, then the function of
base class gets overridden*/

#include <iostream>
using namespace std;

/* base class */
class Parent {
    public:
    void    print() {
        cout << "This is the function of base class." << endl;
    }
};

class child: public Parent {
    public:
    void    print() {
        cout << "This is the function of derived class." << endl;
    }
};

int main() {
    child obj;
    obj.print();

    /* Checked something */
    Parent obj1;
    obj1.print();
    
    return 0;
}
