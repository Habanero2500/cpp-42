/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:08:19 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/28 22:23:56 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void )
{
}

Intern& Intern::operator= ( const Intern& )
{
    return (*this);
}

Intern::Intern ( const Intern& copy )
{
    (void) copy;
}

Intern::~Intern ( void )
{
}

AForm* Intern::makeShrubbery( const std::string& target) const
{
    ShrubberyCreationForm *form = new ShrubberyCreationForm(target);
    return form;
}

AForm* Intern::makeRobotomy( const std::string& target) const
{
    RobotomyRequestForm *form = new RobotomyRequestForm(target);
    return form;
}

AForm* Intern::makePresidential( const std::string& target) const
{
    PresidentialPardonForm *form = new PresidentialPardonForm(target);
    return form;    
}

AForm* Intern::makeForm(std::string type, std::string name)
{
    std::string forms[3];
    forms[0] = "Presidential pardon";
    forms[1] = "Robotomy request";
    forms[2] = "Shrubbery creation";
    
    typedef AForm* (Intern::*FormMaker)(const std::string& target) const; // Pointeur vers une methode membre
    
    FormMaker formMakers[3]; //Initialisation du pointeur vers fonctions membres
    
    formMakers[0] = &Intern::makeShrubbery;
    formMakers[1] = &Intern::makeRobotomy;
    formMakers[2] = &Intern::makePresidential;
        
    for( int i(0); i < 3 ; i++)
    {
        if(type == forms[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return(this->*formMakers[i])(name);
        }
    }
    std::cout << "Incorrect forms name, please manage your intern correctly" << std::endl;
    return(NULL);
}
