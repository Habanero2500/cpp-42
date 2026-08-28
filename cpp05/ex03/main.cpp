/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:07:24 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/28 22:46:18 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main ( void )
{
    Intern julien;

    std::cout << "** TESTS ON INVALID PARAMETERS **" << std::endl;
    AForm *steiv = julien.makeForm("Steiv", "steiv");
    (void)steiv;

    Bureaucrat ceo("CEO", 1);
    
    std::cout << "** TESTS ON VALID PARAMETERS **" << std::endl;
    AForm *ppf = julien.makeForm("Presidential pardon", "PPF");
    AForm *rrf = julien.makeForm("Robotomy request", "RRF");
    AForm *scf = julien.makeForm("Shrubbery creation", "SCF");
    
    if(ppf)
    {
        ceo.signForm(*ppf);
        ceo.executeForm(*ppf);
        delete ppf;
    }
    if(ppf)
    {
        ceo.signForm(*rrf);
        ceo.executeForm(*rrf);
        delete rrf;
    }
    if(scf)
    {
        ceo.signForm(*scf);
        ceo.executeForm(*scf);
        delete scf;
    }
    return 0;   
}