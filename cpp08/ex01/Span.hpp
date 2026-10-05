/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:19:49 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/03 12:42:23 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream> 
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

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

    Span( unsigned int i );
    
    class IndexOutOfBonds : public std::exception{
        public : 
        virtual const char *what() const throw()
        {
            return "Index out of Bonds";    
        }
    };

    class SpanTooShort : public std::exception
    {
        public : 
        virtual const char *what() const throw()
        {
            return "Vector too short to calculate any span";    
        }
    };
    
    class ContainerTooSmall : public std::exception
    {
        public : 
        virtual const char *what() const throw()
        {
            return "Containers can not have an empty size or have a size 1.";    
        }
    };

    
    
    void tryToPush( int i );
    void addNumber ( int i );

    void addRange ( std::vector<int>::iterator begin, std::vector<int>::iterator end );
    
    long long shortestSpan( void );
    long long longestSpan( void  );
    void displaySpan( void );
    void checkNumbers( void );

};

#endif 