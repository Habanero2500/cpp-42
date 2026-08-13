/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 12:28:24 by jmetayer          #+#    #+#             */
/*   Updated: 2026/07/09 12:58:21 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <cmath>

class Fixed{
    
    private :

    int _nbr;
    static const int _numberBits = 8;
     
    public :
    //Canonical form:
    Fixed( void );
    Fixed( int nbr);
    Fixed( float nbr);
    ~Fixed( void );
    Fixed( const Fixed& copy ) ;
    
    //Comparison operators:
    bool operator<( const Fixed comp ) const;
    bool operator>( const Fixed comp ) const;
    bool operator<=( const Fixed comp ) const;
    bool operator>=( const Fixed comp ) const;
    bool operator==( const Fixed comp ) const;
    bool operator!=( const Fixed comp ) const;
    
    //Arithmetic operators:
    Fixed operator+( const Fixed &add ) const;
    Fixed operator-( const Fixed &comp ) const;
    Fixed operator*( const Fixed &comp ) const;
    Fixed operator/( const Fixed &comp ) const; // Division par 0 a securiser ??

    //Increment/decrement operators:
    Fixed& operator++( void ); // pre incrementation
    Fixed operator++( int ); // post incrementation
    Fixed& operator--( void ); // pre decrementation
    Fixed operator--( int ); // post decrementation

    //min/max:
    static const Fixed& min (const Fixed &a, const Fixed &b);
    Fixed& min (Fixed &a, Fixed &b);
    static const Fixed& max (const Fixed &a, const Fixed &b);
    Fixed& max (Fixed &a, Fixed &b);

    //Setters/Getters
    void setRawBits( int nbr );
    int getRawBits( void ) const;
    int toInt( void ) const;
    float toFloat( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value); // Surcharge de l'opérateur <<

#endif