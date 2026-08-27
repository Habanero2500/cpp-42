/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:16:21 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/27 18:18:41 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONORM_HPP
#define PRESIDENTIALPARDONORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : virtual public AForm 
{
    private :
    std::string _target;

    public :

    //Orthodox Canonical Form + constructors
    PresidentialPardonForm( void );
    PresidentialPardonForm& operator=( const PresidentialPardonForm& copy);
    PresidentialPardonForm( const PresidentialPardonForm& copy);
    ~PresidentialPardonForm( void );

    PresidentialPardonForm( std::string _copy );
    void	executeForm(void) const;

    //getter
    std::string const&	getTarget(void) const;
};


#endif