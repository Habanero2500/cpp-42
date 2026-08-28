/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:16:21 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/27 18:20:50 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : virtual public AForm 
{
    private :
    std::string _target;

    public :

    //Orthodox Canonical Form + constructors
    ShrubberyCreationForm( void );
    ShrubberyCreationForm& operator=( const ShrubberyCreationForm& copy);
    ShrubberyCreationForm( const ShrubberyCreationForm& copy);
    ~ShrubberyCreationForm( void );

    ShrubberyCreationForm( std::string _copy );
    void	executeForm(void) const;

    //getter
    std::string const&	getTarget(void) const;
};

#endif