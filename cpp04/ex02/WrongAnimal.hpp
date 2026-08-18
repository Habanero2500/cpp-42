/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:41:07 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/12 13:29:02 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    
    protected : 

    std::string _type;

    public : 

    //Orthodox Canonical form
    WrongAnimal( void );
    virtual ~WrongAnimal ( void );
    WrongAnimal ( const WrongAnimal& type );
    WrongAnimal& operator=(const WrongAnimal& other);
    WrongAnimal( std::string type);

    //Specific member
    std::string getType( void ) const ;
    void makeSound( void ) const;
    
};

#endif