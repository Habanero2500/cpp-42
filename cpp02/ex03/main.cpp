/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 14:31:31 by jmetayer          #+#    #+#             */
/*   Updated: 2026/07/28 13:32:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <cstdlib>

int main(void)
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    std::cout << std::boolalpha;

    // Point à l'intérieur
    Point p1(1, 1);
    std::cout << "Test 1 (inside) : " << bsp(a, b, c, p1) << std::endl;

    // Point à l'extérieur
    Point p2(10, 10);
    std::cout << "Test 2 (outside) : " << bsp(a, b, c, p2) << std::endl;

    // Sur un sommet
    Point p3(0, 0);
    std::cout << "Test 3 (On a point) : " << bsp(a, b, c, p3) << std::endl;

    // Sur une arête
    Point p4(5, 0);
    std::cout << "Test 4 (edge) : " << bsp(a, b, c, p4) << std::endl;

    // Très proche de l'arête mais à l'intérieur
    Point p5(5, 0.1f);
    std::cout << "Test 5 (near edge but inside) : " << bsp(a, b, c, p5) << std::endl;

    // Très proche de l'arête mais à l'extérieur
    Point p6(5, -0.1f);
    std::cout << "Test 6 (outside) : " << bsp(a, b, c, p6) << std::endl;
    
    // std::cout << "A : x = " << a.getX() << std::endl;
    // std::cout << "A : y = " << a.getY() << std::endl;
    // std::cout << "B : x = " << b.getX() << std::endl;
    // std::cout << "B : y = " << b.getY() << std::endl;
    // std::cout << "C : x = " << c.getX() << std::endl;
    // std::cout << "C : y = " << c.getY() << std::endl;
    // std::cout << "P1 : x = " << p1.getX() << std::endl;
    // std::cout << "P1 : y = " << p1.getY() << std::endl;
    return (0);
}