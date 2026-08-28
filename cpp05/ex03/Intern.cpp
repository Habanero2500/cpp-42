/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:08:19 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/28 17:21:11 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern( void )
{
}

Intern& Intern::operator= ( const Intern& copy )
{       
}

Intern::Intern ( const Intern& copy )
{   
}

Intern::~Intern ( void )
{
}



AForm* Intern::makeForm(std::string type, std::string name)
{
    std::string forms[3];
    forms[0] = "Presidential pardon";
    forms[1] = "Robotomy request";
    forms[2] = "Shrubbery creation";
    
    for( int i(0); i < 3 ; i++)
    {
        if(type = forms[i])
            
    }
}