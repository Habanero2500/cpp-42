/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 11:22:24 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/08 16:08:13 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN{
  
    private :
        
    std::stack<long long> _stack;

    
    public : 

    class DivisionException : public std::exception{

    public : 
    virtual const char *what() const throw()
    {
       return "Division by 0 is forbidden";
    }
    };

    class WrongCombinationException : public std::exception{

    public : 
    virtual const char *what() const throw()
    {
       return "Wrong combination";
    }
    };
    
    class NoSeparationException : public std::exception{

    public : 
    virtual const char *what() const throw()
    {
       return "Everything has to be seperated by a space";
    }
    };
    
    class WrongCharacterException : public std::exception{

        public : 
        virtual const char *what() const throw()
        {
            return "Wrong character used";
        }
    };

    class NotEnoughOperatorException : public std::exception{

        public : 
        virtual const char *what() const throw()
        {
            return "Too many elements for the number of operators";
        }
    };
    
    class NotEnoughElementsException : public std::exception 
    {
        public :
        virtual const char *what() const throw()
        {
            return "Too many operators for the number of elements";
        }
    };

    class WrongOrderException : public std::exception 
    {
        public :
        virtual const char *what() const throw()
        {
            return "Too many operators for the number of elements";
        }
    };

    //Forme canonique
    // RPN( void );
    // RPN (const RPN& copy);
    // RPN& operator=(const RPN& copy);
    // ~RPN( void );
    
    RPN(const char *str);
    
    //Parsing
    int checkElement( const char* str );
    int parseAndCompute( const char *str );
    
    
};



#endif