/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:59:47 by jmetayer          #+#    #+#             */
/*   Updated: 2026/09/01 16:01:01 by jmetayer         ###   ########.fr       */
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
    long long res(1);
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


// Double jusqu'a 16 nombres apres la virgule contre 7 pour le float. Float finit par un f 

static bool isDouble(const std::string &str)
{
    unsigned int i(0);
    bool point = false;
    


    i = 0;
    while(i < str.length())
    {
        if( str[i] < '0' || str[i] > '9' || str[i] == '.')
            return false;
        if(str[i] != 0 && str[i] == '.' && point == false)
            point = true;
        if(str[i] != 0 && str[i] == '.' && point == true)
            return false;
        i++;
    }
    if(point == true)
        return true;
    return false;
}

bool isDouble(const std::string &str)
{
    long long res(1);
    unsigned int i(0);
    if(str[0] == '-' || str[0] == '+')
    {
        if(str[0] == '-')
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

static e_type whichType( const std::string &str )
{
    if( isInt(str) == true)
        return INT;
    else if( isChar(str) == true)
        return CHAR;
    else if( isDouble(str) == true)
        return DOUBLE;

    else
        return NONE;
}


void ScalarConverter::convert( const std::string &str )
{
    e_type type = whichType(str);
    if(type == INT)
        std::cout << "Type : INT" << std::endl; 
    else if(type == CHAR)
        std::cout << "Type : CHAR" << std::endl;
    else
        std::cout << "Type : NONE" << std::endl;

}
