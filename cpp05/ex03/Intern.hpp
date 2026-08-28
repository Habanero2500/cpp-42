/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:00:46 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/28 16:57:32 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
    
    private : 

    public :
    
    //Orthodox canonical Form
    Intern( void );
    Intern& operator= ( const Intern& copy );
    Intern ( const Intern& copy );
    ~Intern ( void );

    
    //Specific member 
    AForm* makeForm(std::string, std::string);
    
};

#endif