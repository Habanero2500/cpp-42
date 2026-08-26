/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:16:46 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/26 20:31:16 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm( void ) : AForm("Default_SCF", 0, 145, 137) 
{
    std::cout << "Default Constructor for SCF used" << std::endl;
}

ShruberryCreationForm& ShruberryCreationForm::operator=( const ShruberryCreationForm& copy)
{
    std::cout << "Overload operator = used for ShrubberyCreationForm" << std::endl; 
    if(this != &copy)
    {
        _target = copy.getTarget();
    }
    return (*this);
}

ShruberryCreationForm::ShruberryCreationForm( const ShruberryCreationForm& copy) : AForm(copy)
{
    std::cout << "Copy destructor for ShrubberyCreationForm" << std::endl; 
    _target = copy.getTarget();
}
ShruberryCreationForm::~ShruberryCreationForm( void )
{
    std::cout << "Default destructor for ShrubberyCreationForm" << std::endl; 
}
ShruberryCreationForm::ShruberryCreationForm( std::string name ) : AForm(name, 0, 145, 137) 
{
    std::cout << "Classical constructor used" << std::endl;
}

std::string const&	ShruberryCreationForm::getTarget( void ) const
{
    return (_target);
}

void	ShruberryCreationForm::execute(void) const
{
    if(this->AForm::getSigned())
    {
        std::string name = "_shruberry";
        name = this->_target + name;
        std::ofstream file((name.c_str()));
        if (file.is_open())
        {
            std::cout << "          ⭐ " << std::endl;           
            std::cout << "          /\\ " << std::endl;
            std::cout << "         / o\\ " << std::endl;  
            std::cout << "        /o   \\ " << std::endl;
            std::cout << "        /   o\\ " << std::endl;
            std::cout << "       /o o   \\  " << std::endl;
            std::cout << "      /     o  \\ " << std::endl;
            std::cout << "      /  o    o\\ " << std::endl;
            std::cout << "     / o    o   \\ " << std::endl;
            std::cout << "    /     o  o   \\ " << std::endl;
            std::cout << "    /o  o   o   o\\ " << std::endl;
            std::cout << "         |   |      " << std::endl;
            std::cout << "         |   |      " << std::endl;
            file.close();
        }
        else
            std::cout << "Error while opening the file !" << std::endl;
    }
        
    
    

}