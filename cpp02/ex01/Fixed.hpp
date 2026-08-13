/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:19:41 by jmetayer          #+#    #+#             */
/*   Updated: 2026/07/08 12:32:10 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    
    private :
    
    int _nbr; // La subtilite de l'exercice et que ce int doit permettre de stocker des float et des int.
    // Pour ce faire on le multiplie a chaque fois par 256 cela permet de stocker et des float et des int. 
    // On le redeivise par 256 par la suite pour obtenir le nombre qui etait stocke dedans (fonction assuree par toFloat)
    static const int _numberBits = 8;
    
    public :

    Fixed (void); // Constructeur par défaut
    Fixed( const int nbr ); // Constructeur int
    Fixed(const float nbr);
    Fixed( const Fixed& copy ) ; //A faire ; Constructeur de copie : construit un objet a partir d'un autre
    Fixed& operator=( const Fixed& other ); // surcharge de l'opérateur = 
    ~Fixed (void); // Destructeur
    
    int getRawBits( void ) const;
    void setRawBits( int nbr );
    int toInt(void) const;
    float toFloat(void) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &value); // Surcharge de l'opérateur <<


#endif