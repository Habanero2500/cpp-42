/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:16:46 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/27 22:05:04 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("Default_SCF", 0, 72, 45), _target ("Default_RRF")
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& copy)
{
    std::cout << "Overload operator = used for RobotomyRequestForm" << std::endl; 
    if(this != &copy)
    {
        _target = copy.getTarget();
    }
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy) : AForm(copy)
{
    _target = copy.getTarget();
}
RobotomyRequestForm::~RobotomyRequestForm( void )
{
}
RobotomyRequestForm::RobotomyRequestForm( std::string name ) : AForm("RobotomyRequestForm", 0, 72, 45), _target(name) 
{
}

std::string const&	RobotomyRequestForm::getTarget( void ) const
{
    return (_target);
}

void	RobotomyRequestForm::executeForm(void) const
{
    if(this->AForm::getSigned())
    {
        std::cout << "Brrrrrr brrr brrrrrrr" << std::endl;
         if(std::rand() % 2 == 0)
            std::cout << _target << " has been robotomized successfully !" << std::endl;
        else 
            std::cout << "Unfortunately, the robotomy failed..." << std::endl;
    }
}
