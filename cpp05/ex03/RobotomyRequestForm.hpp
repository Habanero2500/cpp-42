/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:16:21 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/28 14:14:00 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : virtual public AForm 
{
    private :
    std::string _target;

    public :

    //Orthodox Canonical Form + constructors
    RobotomyRequestForm( void );
    RobotomyRequestForm& operator=( const RobotomyRequestForm& copy);
    RobotomyRequestForm( const RobotomyRequestForm& copy);
    ~RobotomyRequestForm( void );

    RobotomyRequestForm( std::string _copy );
    void	executeForm(void) const;

    //getter
    std::string const&	getTarget(void) const;
};


#endif