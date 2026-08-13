/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:15:08 by jmetayer          #+#    #+#             */
/*   Updated: 2026/07/02 18:04:03 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

//La forme canonique correspond simplement a une classe ayant : un constructeur par defaut, 
// un constructeur de copie, un operateur d'affectation et un destructeur

class Fixed 
{
    private : 
    int _integer;
    static const int _numberBits = 8;
    
    public :
    
    Fixed( void ); // Constructeur par defaut
    Fixed ( const Fixed& copy ); // Constructeur de copie : construit un objet a partir d'un autre deja existant
    Fixed& operator=( const Fixed& other ); // Operateur d'affectation : copie les donnes dans un objet deja existant
    ~Fixed(); // Destructeur 
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    

};

#endif