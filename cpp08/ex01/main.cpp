/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:14:13 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/01 18:27:48 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


//La je check la taille du _size mais pas les nombres stored dedans 
int main()
{
    std::cout << "**** MANDATORY MAIN ****" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << std::endl << "**** EXTRA TESTS ****" << std::endl;
    ////////////////////////////////////////////////////////////////////

    std::cout << "- INT_MIN et INT_MAX" << std::endl;
    Span test1(2);
    test1.addNumber(INT_MIN);
    test1.addNumber(INT_MAX);
    std::cout << test1.shortestSpan() << std::endl;
    std::cout << test1.longestSpan() << std::endl;
    ////////////////////////////////////////////////////////////////////
    std::cout << "- Exception with empty span" << std::endl;
    Span test3(100);

    try
    {
        std::cout << test3.shortestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    ////////////////////////////////////////////////////////////////////
    std::cout << "- Exception with size 1" << std::endl;

    try
    {
        Span test2(1);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    


    
    return 0;
}