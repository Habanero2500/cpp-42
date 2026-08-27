/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:07:24 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/27 22:32:32 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ( void )
{
    Bureaucrat intern("intern", 150);
    Bureaucrat junior("junior", 145);
    Bureaucrat senior("senior", 72);
    Bureaucrat manager("manager", 25);
    Bureaucrat ceo("CEO", 1);
    
    ShrubberyCreationForm test2("test2");
    std::cout << test2;
    RobotomyRequestForm test1("test1");
    std::cout << test1;
    PresidentialPardonForm test("test");
    std::cout << test;


    
    std::cout << std::endl << "** TEST WITH AN UNSIGNED SCF**" << std::endl << std::endl;
    try
    {
        std::cout << test2;
        test2.execute(intern);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    junior.signForm(test2);
    
    std::cout << std::endl << "** TEST WITH A SIGNED SCF BUT A TOO LOW GRADE **" << std::endl << std::endl;
    try
    {
        test2.execute(intern);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << std::endl << "** TEST WITH A SIGNED SCF WITH SUFFICIENT GRADE **" << std::endl << std::endl;    
    try
    {
        
        test2.execute(ceo);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    
    // try
    // {
    //     test.execute(low);
    // }
    // catch (std::exception& e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
}
// int main( void )
// {

    // std::cout << "** ORTHODOX CANONICAL FORM TEST **" << std::endl << std::endl;
    // ShrubberyCreationForm test;
    // ShrubberyCreationForm test2("TIKTAKTOUK");
    // std::cout << test.getTarget() << std::endl;
    // std::cout << test2.getTarget() << std::endl; 
    
    // RobotomyRequestForm test;
    // PresidentialPardonForm test2("TIKTAKTOUK");
    // std::cout << test.getTarget() << std::endl;
    // std::cout << test2.getTarget() << std::endl; 
    
    // std::cout << std::endl << "** INITIALIZE THE BUREAUCRAT **" << std::endl << std::endl;

   
    // Bureaucrat exact("Michmich", 145);
    // Bureaucrat high("JP", 130);


    // std::cout << std::endl << "** SHOW THE STATE OF THE FORM BEFORE SIGNATURE **" << std::endl << std::endl;
    // std::cout << test << std::endl;
    // std::cout << test2 << std::endl;     
        
    // std::cout << std::endl << "** LET'S SIGN **" << std::endl << std::endl;

    // low.signForm(test);
    // low.signForm(test2);
    // std::cout << test << std::endl;
    // std::cout << test2 << std::endl;  

    
    // exact.signForm(test);
    // exact.signForm(test2);
    // std::cout << test << std::endl;
    // std::cout << test2 << std::endl;

    // high.signForm(test);
    // high.signForm(test2);

    // std::cout << std::endl << "** SHOW THE STATE OF THE FORM AFTER SIGNATURE **" << std::endl << std::endl;
// }