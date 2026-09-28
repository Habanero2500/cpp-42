/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 18:28:02 by jmetayer          #+#    #+#             */
/*   Updated: 2026/09/28 18:33:49 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array {

    private :
     
    T           *_array; 
    unsigned int _size;
    
    public : 
    
    Array( void );
    Array( unsigned int  n );
    Array ( const Array& copy );
    Array& operator=( const Array& copy );
    ~Array( void );
    
    T& operator [](unsigned int index);
    const T& operator [](unsigned int index) const;
    
    unsigned int size( void ) const;
    void printArray ( void ) const;
    
    class IndexOutOfBounds : public std::exception {
        virtual const char* what( void ) const throw() {
            return ("Index out of bonds");
        }
    };
    
};

#include "Array.tpp"


#endif