/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 17:45:59 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/18 18:11:49 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( void )
{
    std::cout << "Bureaucrat default constructor is used" << std::endl;
}

Bureaucrat::Bureaucrat ( std::string name )
{
    std::cout << "Bureaucrat classical constructor is used" << std::endl; 
    _name = name; 
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& copy )
{
    std::cout << "Bureaucrat operator overload = is called" << std::endl; 
    if(*this != copy)
    {
        _name = copy.getName();
        _range = copy.getRange();
    }
    return(*this);   
}

Bureaucrat::Bureaucrat ( const Bureaucrat &copy )
{
    std::cout <<"Bureaucrat copy constructor called" << std::endl;
    _name = copy.getName();
    _range = copy.getRange();
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor is called" << std::endl; 
}

void Bureaucrat::setName( std::string name )
{
    _name = name;
}
std::string Bureaucrat::getName( void )
{
    return (this->_name);
}
void Bureaucrat::setRange( int range )
{
    _range = range;
}
    
int Bureaucrat::getRange ( void )
{
    return (_range);
}