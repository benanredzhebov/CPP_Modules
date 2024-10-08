/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_function.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:32:48 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/08 16:38:21 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

class Base {
    public:
    virtual void    print() {
        cout << "This is the function of base class" << endl;
    }
};

class Derived: public Base {
    public:
    void    print() {
        cout << "This is the function of derived class" << endl;
    }
};

int main() {
    Base* b;
    Derived d;
    b = &d;
    b->print();
    
    return 0;
}