/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 13:29:41 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/08 15:59:40 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"



void RPN::parseAndCompute( const char *str )
{
    long long res(0);
    
    for(int i(0); str[i] ; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            _stack.push(str[i] - '0');
            continue;
        }
        else if(str[i] == ' ')
            continue;
        if (str[i] == '-')
        {
            res = _stack.top();
            _stack.pop();
            res -= _stack.top();
            _stack.pop();
            _stack.push(res);
        }
        if (str[i] == '+')
        {
            res = _stack.top();
            _stack.pop();
            res += _stack.top();
            _stack.pop();
            _stack.push(res);
        }
        if (str[i] == '*')
        {
            res = _stack.top();
            _stack.pop();
            res *= _stack.top();
            _stack.pop();
            _stack.push(res);
        }
        if (str[i] == '/')
        {
            res = _stack.top();
            _stack.pop();
            res /= _stack.top();
            _stack.pop();
            _stack.push(res);
        }
    }
    std::cout << res << std::endl;    
}


int RPN::checkElement( const char *str )
{
    int countElement(0);
    int countOperator(0);
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
            countOperator++;
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
        if(countOperator >= countElement)
            return 5;
    }

    if(countElement > countOperator + 1)
        return 2;
    else if(countElement < countOperator + 1)
        return 1;
    else
        return 0;
}

RPN::RPN( const char *str )
{
    int check(checkElement(str));
    
    if(check == 1)
        throw NotEnoughElementsException();
    if(check == 2)
        throw NotEnoughOperatorException();
    if(check == 3)
        throw WrongCharacterException();
    if(check == 4)
        throw NoSeparationException();
    if(check == 5)
        throw WrongCombinationException();
    if(check == 0)
        parseAndCompute(str);
}