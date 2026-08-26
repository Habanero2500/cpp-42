/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:16:21 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/26 16:39:23 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class ShruberryCreationForm : virtual public AForm 
{
    private :
    std::string _target;

    public :

    //Orthodox Canonical Form + constructors
    ShruberryCreationForm( void );
    ShruberryCreationForm& operator=( const ShruberryCreationForm& copy);
    ShruberryCreationForm( const ShruberryCreationForm& copy);
    ~ShruberryCreationForm( void );

    ShruberryCreationForm( std::string _copy );
    void	execute(void) const;

    //getter
    std::string const&	getTarget(void) const;
};

#endif