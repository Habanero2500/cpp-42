/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 13:29:41 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/08 14:56:22 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"



// std::stack<long long> RPN::parsing( const char* str)
// {
    
// }
int RPN::checkElement( const char *str )
{
    int countElement(0);
    int countOpertor(0);
    bool inANumber(false);
    bool inAnOperator(false);
    
    for (int i(0) ; str[i] ; i++)
    {
        if(!(str[i] >= '0' && str[i] <= '9') && str[i] != '*' && str[i] != '/' && str[i] != '-' && str[i] != '+' && str[i] != ' ')
            return 3;
        
        if( str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' )
        {
            if(inAnOperator == true || inANumber == true)    
                return 4;
            countOpertor++;
            inAnOperator = true;
        }
        if(str[i] == ' ')
        {
            inAnOperator = false;
            inANumber = false;
        }
        if( str[i] >= '0' && str[i] <= '9' )
        {
            if(inAnOperator == true || inANumber == true)    
                return 4;
            countElement++;
            inANumber = true;
        }
    }
    if(countElement > countOpertor + 1)
        return 2;
    else if(countElement < countOpertor + 1)
        return 1;
    else
        return 0;
}

RPN::RPN( const char *str )
{
    int check(checkElement(str));
    if(check == 1)
        throw NotEnoughOperatorException();
    if(check == 2)
        throw NotEnoughElementsException();
    if(check == 3)
        throw WrongCharacterException();
    if(check == 4)
        throw NoSeparationException();
    
    // _stack = parsing(str);
    
    
}