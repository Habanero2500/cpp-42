/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 17:37:13 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/18 17:45:27 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat{
    private : 

    const std::string _name;
    int _range;
    
    public : 

    //Constructors and Orthodox canonical form
    Bureaucrat ( void );
    Bureaucrat ( std::string name );
    Bureaucrat& operator=( const Bureaucrat& copy );
    Bureaucrat ( const Bureaucrat &copy );
    ~Bureaucrat();

    void setName( std::string name );
    std::string getName( void );
    void setRange( int range );
    int getRange ( void );
    
    
    
    
    
    
    
    
};

#endif