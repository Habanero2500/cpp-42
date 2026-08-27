/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:16:46 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/27 16:17:31 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("Default_PPF", 0, 25, 5), _target ("Default_PPF")
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& copy)
{
    std::cout << "Overload operator = used for PresidentialPardonForm" << std::endl; 
    if(this != &copy)
    {
        _target = copy.getTarget();
    }
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy) : AForm(copy)
{
    _target = copy.getTarget();
}
PresidentialPardonForm::~PresidentialPardonForm( void )
{
}
PresidentialPardonForm::PresidentialPardonForm( std::string name ) : AForm("PresidentialPardonForm", 0, 25, 5), _target(name) 
{
}

std::string const&	PresidentialPardonForm::getTarget( void ) const
{
    return (_target);
}

void	PresidentialPardonForm::executeForm(void) const
{
    if(this->AForm::getSigned())
    {
        std::cout << _target << " has benn pardoned by Zaphod Beeblebrox." << std::endl; 
    }
}
