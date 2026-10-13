/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 11:22:24 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/13 15:54:34 by jmetayer         ###   ########.fr       */
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
    
    //**** ORTHODOX CANOMICAL FORM ****
    RPN( void ){} 
    RPN (const RPN& copy) : _stack (copy._stack) {}
    RPN& operator=(const RPN& copy){
        if(this != &copy)
            _stack = copy._stack;
        return *this;
    }
    ~RPN( void ){}
    
    RPN(const char *str);

    //**** PARSING AND EXEC ****
    int checkElement( const char* str );
    int parseAndCompute( const char *str );

    // **** EXCEPTIONS ****
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


    
    
};



#endif