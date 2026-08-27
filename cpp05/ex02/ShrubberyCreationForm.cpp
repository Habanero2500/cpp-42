/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:16:46 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/27 22:10:52 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("Default_SCF", 0, 145, 137), _target ("Default_SCF")
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& copy)
{
    if(this != &copy)
    {
        _target = copy.getTarget();
    }
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy) : AForm(copy)
{
    _target = copy.getTarget();
}
ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
}
ShrubberyCreationForm::ShrubberyCreationForm( std::string name ) : AForm("ShrubberyCreationForm", 0, 145, 137), _target(name) 
{
}

std::string const&	ShrubberyCreationForm::getTarget( void ) const
{
    return (_target);
}

void	ShrubberyCreationForm::executeForm( void ) const
{
    if(this->AForm::getSigned())
    {
        std::string name = "_shruberry";
        name = this->_target + name;
        std::ofstream file((name.c_str()));
        if (file.is_open())
        {
            file << "          ⭐ " << std::endl;           
            file << "          /\\ " << std::endl;
            file << "         / o\\ " << std::endl;  
            file << "        /o   \\ " << std::endl;
            file << "        /   o\\ " << std::endl;
            file << "       /o o   \\  " << std::endl;
            file << "      /     o  \\ " << std::endl;
            file << "      /  o    o\\ " << std::endl;
            file << "     / o    o   \\ " << std::endl;
            file << "    /     o  o   \\ " << std::endl;
            file << "    /o  o   o   o\\ " << std::endl;
            file << "         |   |      " << std::endl;
            file << "         |   |      " << std::endl;
            file.close();
        }
        else
            std::cout << "Error while opening the file !" << std::endl;
    }
}
