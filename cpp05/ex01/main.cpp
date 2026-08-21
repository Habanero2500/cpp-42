/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:07:24 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/21 16:31:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main( void )
{
    // Form test1;
    // std::cout << test1;
    // Form test2("Test");
    // std::cout << test2;
    // Form test3("Test", 1, 70, 70);
    // std::cout << test3;
    // Form test4;
    // std::cout << test4;
    // test4 = test3;
    // std::cout << test4;

try
{
    Form test("Test", 0, 0, 0);
}
catch (const Form::GradeTooHighException& e)
{
    std::cout << e.what() << std::endl;
}
catch (const Form::GradeTooLowException& e)
{
    std::cout << e.what() << std::endl;
}
try
{
    Form test1("Test", 0, 170, 60);
}
catch (const Form::GradeTooHighException& e)
{
    std::cout << e.what() << std::endl;
}
catch (const Form::GradeTooLowException& e)
{
    std::cout << e.what() << std::endl;
}
try
{
    Form test2("Test", 0, 160, 70);
}
catch (const Form::GradeTooHighException& e)
{
    std::cout << e.what() << std::endl;
}
catch (const Form::GradeTooLowException& e)
{
    std::cout << e.what() << std::endl;
}


     
    std::cout << "** CONTRACT CREATION **" << std::endl << std::endl;
    Form testlow("Lame contract", 0, 150, 150);
    Form testaverage("Social contract", 0, 70, 70);
    Form testhigh("Devils contract", 0, 1, 1);
    std::cout << testlow;
    std::cout << testaverage;
    std::cout << testhigh;

    std::cout<< std::endl << "** LOW BUREAUCRAT CREATION **" << std::endl << std::endl;
    Bureaucrat  pierre("Pierre", 150);
    pierre.signForm(testlow);
    pierre.signForm(testaverage);
    pierre.signForm(testhigh);
    std::cout << testlow;
    std::cout << testaverage;
    std::cout << testhigh;
    
    std::cout<< std::endl << "** MID BUREAUCRAT CREATION **" << std::endl << std::endl;
    
    for(int i(0); i < 80; i++)
        pierre.upGrade();
    std::cout << pierre;
    pierre.signForm(testlow);
    pierre.signForm(testaverage);
    pierre.signForm(testhigh);
    std::cout << testlow;
    std::cout << testaverage;
    std::cout << testhigh;
    
    std::cout<< std::endl << "** PARTNER BUREAUCRAT CREATION **" << std::endl << std::endl;

    for(int i(0); i < 69; i++)
        pierre.upGrade();
    std::cout << pierre;
    pierre.signForm(testlow);
    pierre.signForm(testaverage);
    pierre.signForm(testhigh);
    std::cout << testlow;
    std::cout << testaverage;
    std::cout << testhigh;
    
    

    
    

    
}