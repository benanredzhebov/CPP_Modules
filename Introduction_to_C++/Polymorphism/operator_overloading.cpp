/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_overloading.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:49:04 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/08 16:17:43 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

class OverLoad {
    private:
    int n1;
    int n2;

    public:
    OverLoad(int num1, int num2) {
        int res;
        n1 = num1;
        n2 = num2;
        res = num1 - num2;
        cout << "res: " << res << endl;
    }

    void    operator-() {
        n1 = -n1;
        n2 = -n2;
    }

    void    display() {
        cout << "n1 = " << n1 << ";"<< " n2 = " << n2 << endl;
    }
};

int main() {
    OverLoad o1(6,8);
    -o1;
    o1.display();
    return 0;
}