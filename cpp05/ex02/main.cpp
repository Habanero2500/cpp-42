/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:07:24 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/26 20:26:15 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
    ShruberryCreationForm test;
    ShruberryCreationForm test2("test");
    // Bureaucrat low("Dylan", 150);
    // Bureaucrat exact("Michmich", 145);
    // Bureaucrat high("JP", 130);

    
    std::cout << test << std::endl;
    std::cout << test2 << std::endl;        
        
}