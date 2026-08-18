/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:41:07 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/11 19:31:08 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    
    protected : 

    std::string _type;

    public : 

    //Orthodox Canonical form
    Animal( void );
    virtual ~Animal ( void );
    Animal ( const Animal& type );
    Animal& operator=(const Animal& other);
    Animal( std::string type);

    //Specific member
    std::string getType( void ) const ;
    virtual void makeSound( void ) const;
    
};

#endif