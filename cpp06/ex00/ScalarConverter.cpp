/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:59:47 by jmetayer          #+#    #+#             */
/*   Updated: 2026/09/01 13:47:22 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(const std::string &str)
{
    if(str.length() == 1 && isalpha(str[0]))
        return true;
    return false;
}
static bool isInt ( const std::string &str )
{
    double long res(1);
    unsigned int i(0);
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            res *= -1;
        i++;
    }
    while(i < str.length())
    {
        if( str[i] < '0' || str[i] > '9')
            return false;
        res = res * 10 + (str[i] - '0');
        i++;
    }
    if(res <= INT_MAX && res >= INT_MIN)
        return true;
    return false;
}


// bool isFloat(const std::string &str)
// {
    
// }
// bool isDouble(const std::string &str)
// {
    
// }

static e_type whichType( const std::string &str )
{
    if( isInt(str) == true)
        return INT;
    else if( isChar(str) == true)
        return CHAR;
    // else if( isDouble(str) == true)
    //     return DOUBLE;
    // else if( isFloat (str) == true )
    //     return FLOAT;
    else
        return NONE;
}


void ScalarConverter::convert( const std::string &str )
{
    e_type type = whichType(str);
    std::cout << "Type : " << type << std::endl; 
}
