/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 17:37:13 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/18 18:13:37 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat{
    private : 

    const std::string _name;
    int _grade;
    
    public : 

    //Constructors and Orthodox canonical form
    Bureaucrat ( void );
    Bureaucrat ( std::string name );
    Bureaucrat& operator=( const Bureaucrat& copy );
    Bureaucrat ( const Bureaucrat &copy );
    ~Bureaucrat();

    void setName( std::string name );
    std::string getName( void );
    void setGrade( int grade );
    int getGrade ( void );
    
    
    
    
    
    
    
    
};

#endif