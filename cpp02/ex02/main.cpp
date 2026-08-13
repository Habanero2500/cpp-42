/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 12:26:28 by jmetayer          #+#    #+#             */
/*   Updated: 2026/07/09 13:29:10 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}

// int main( void )
// {
//     Fixed a(5);
//     Fixed b(10);
//     Fixed c;
//     static const Fixed d( 5.05f );
//     static const Fixed var( 1.99f );
//     std::cout << "Surcharge de l'operateur << pour afficher a : " << a << std::endl;
//     std::cout << "Surcharge de l'operateur << pour afficher b : " << b << std::endl;
//     std::cout << "A < B ? Si 1 oui, si 0 non : " << (a < b) << std::endl;
//     std::cout << "A > B ? Si 1 oui, si 0 non : " << (a > b) << std::endl;
//     std::cout << "A <= B ? Si 1 oui, si 0 non : " << (a <= b) << std::endl;
//     std::cout << "A >= B ? Si 1 oui, si 0 non : " << (a >= b) << std::endl;
//     std::cout << "A == B ? Si 1 oui, si 0 non : " << (a == b) << std::endl;
//     std::cout << "A != B ? Si 1 oui, si 0 non : " << (a != b) << std::endl;
//     c = (a + b);
//     std::cout << "A + B = " << c << std::endl;
//     c = (a - b);
//     std::cout << "A - B = " << c << std::endl;
//     c = (a * b);
//     std::cout << "A * B = " << c << std::endl;
//     c = (a / b);
//     std::cout << "A / B = " << c << std::endl;
//     std::cout << "a++ = " << a++ << std::endl;
//     std::cout << "a apres avoir fait a++ = " << a << std::endl;
//     std::cout << "++a = " << ++a << std::endl;
//     std::cout << "a apres avoir fait ++a = " << a << std::endl;
//     std::cout << "a-- = " << a-- << std::endl;
//     std::cout << "a apres avoir fait a-- = " << a << std::endl;
//     std::cout << "--a = " << --a << std::endl;
//     std::cout << "E = " << d << "; F = " << var << std::endl;
//     std::cout << "Valeur min entre d et var = " << Fixed::min(d, var) << std::endl;
//     std::cout << "Valeur max entre d et var = " << Fixed::max(d, var) << std::endl;
    
// }