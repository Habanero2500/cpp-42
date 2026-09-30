/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:19:49 by jmetayer          #+#    #+#             */
/*   Updated: 2026/09/30 17:38:12 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream> 
#include <vector>

using std::cout;
using std::endl;

class Span{
    
    private:
    
    const unsigned int _max;
    std::vector<int> _v; 
    
    public:
    
    Span( void );
    Span( const Span& copy ); 
    Span& operator=( const Span& copy );
    ~Span ( void );

    Span( unsigned int i ) : _max(i) {}; 
    
    void addNumber ( int i );
    void shortestSpan( int i );
    void longestSpan( int i );
    void displaySpan( int i );
    
};



#endif 