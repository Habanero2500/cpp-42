/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:07:24 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/19 18:16:16 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
    // Bureaucrat ludo("Ludo", 50);
    // std::cout << "Value of name : " << ludo.getName() << std::endl;
    // std::cout << "Value of grade : " << ludo.getGrade() << std::endl;
    // // ludo.setGrade(50);
    // Bureaucrat michel(ludo);
    // std::cout << "Value of name : " << michel.getName() << std::endl;
    // std::cout << "Value of grade : " << michel.getGrade() << std::endl;
    // Bureaucrat fred;
    // fred = michel;
    // std::cout << "Value of name : " << fred.getName() << std::endl;
    // std::cout << "Value of grade : " << fred.getGrade() << std::endl;

    Bureaucrat bertrand("Bertrand", 3);
    std::cout << bertrand;
    bertrand.downGrade();
    std::cout << bertrand;
    bertrand.upGrade();
    std::cout << bertrand << std::endl;
    
    std::cout << "TEST EXCEPTION : LIMIT OF 150" << std::endl << std::endl;
    
    try
    {
        Bureaucrat thierry("Thierry", 150);
        std::cout << thierry;
        thierry.downGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << "TEST EXCEPTION : LIMIT OF 150 DURING CONSTRUCTION " << std::endl << std::endl;
    try
    {
        Bureaucrat corentin("Corentin", 160);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << std::endl << "TEST EXCEPTION : LIMIT OF 1" << std::endl << std::endl;
    
    try
    {
        Bureaucrat patrick("Patrick", 1);
        std::cout << patrick;
        patrick.upGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << "TEST EXCEPTION : LIMIT OF 1 DURING CONSTRUCTION " << std::endl << std::endl;
    try
    {
        Bureaucrat jean("Jean", 160);
        std::cout << jean ;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}