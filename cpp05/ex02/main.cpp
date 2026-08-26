/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:07:24 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/27 00:24:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{

    std::cout << "** ORTHODOX CANONICAL FORM TEST **" << std::endl << std::endl;
    ShruberryCreationForm test;
    ShruberryCreationForm test2("test");
    
    std::cout << std::endl << "** INITIALIZE THE BUREAUCRAT **" << std::endl << std::endl;

    Bureaucrat low("Dylan", 150);
    Bureaucrat exact("Michmich", 145);
    Bureaucrat high("JP", 130);

    std::cout << std::endl << "** SHOW THE STATE OF THE FORM BEFORE SIGNATURE **" << std::endl << std::endl;
    std::cout << test << std::endl;
    std::cout << test2 << std::endl;     
        
    std::cout << std::endl << "** LET'S SIGN **" << std::endl << std::endl;

    low.signForm(test);
    low.signForm(test2);
    std::cout << test << std::endl;
    std::cout << test2 << std::endl;  
    test.execute();
    
    exact.signForm(test);
    exact.signForm(test2);
    std::cout << test << std::endl;
    std::cout << test2 << std::endl;
    test.execute();  
    
    high.signForm(test);
    high.signForm(test2);
    test.execute();
    
    // std::cout << std::endl << "** SHOW THE STATE OF THE FORM AFTER SIGNATURE **" << std::endl << std::endl;
}