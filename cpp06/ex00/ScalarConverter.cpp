/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:59:47 by jmetayer          #+#    #+#             */
/*   Updated: 2026/09/03 17:27:19 by jmetayer         ###   ########.fr       */
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
    long long res(0);
    unsigned int i(0);
    if(str[i] == '-' || str[i] == '+')
        i++;
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

//Ne check pas le double max et les 15 chiffres derriere la virgule. 
static bool isDouble(const std::string &str)
{
    if (str == "-inf" || str == "+inf" || str == "nan")
        return true;

    unsigned int i = 0;
    bool point = false;

    if (str[i] == '-' || str[i] == '+')
        i++;
    while (i < str.length())
    {
        if (str[i] == '.')
        {
            if (point)
                return false;
            point = true;
        }
        else if (str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    return point;
}

//Ne check pas le float min ou max, ne check pas les 6 ou 7 chiffres derriere la virgule. 
static bool isFloat(const std::string &str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return true;

    unsigned int i = 0;
    bool point = false;

    if (str[i] == '-' || str[i] == '+')
        i++;

    while (i < str.length())
    {
        if (str[i] == 'f' && i == str.length() - 1)
            return point;

        if (str[i] == '.')
        {
            if (point)
                return false;
            point = true;
        }
        else if (str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    return false;
}

static e_type whichType( const std::string &str )
{
    if (str.empty())
        return NONE;
    if(isInt(str ) == true)
        return INT;
    else if( isChar(str) == true)
        return CHAR;
    else if( isDouble(str) == true)
        return DOUBLE;
    else if( isFloat(str) == true)
        return FLOAT;
    else
        return NONE;
}

static void convertInt( const std::string &str )
{
    int res = std::atoi(str.c_str());
    // Convert to char
    if (res >= 32 && res <= 126)
    {
        char c(res);
        std::cout << "Char conversion : " << c << std::endl;
    }
    std::cout << "Int (original format) : " << res << std::endl;
    std::cout << "Float conversion : " << res << ".0f" << std::endl;
    std::cout << "Double conversion : " << res << ".0" << std::endl;
}
// static void convertChar( const std::string &str )
// {
    
// }
// static void convertFloat( const std::string &str )
// {
    
// }
// static void convertDouble( const std::string &str )
// {
    
// }
// static void convertNone( void )
// {
    
// }

void ScalarConverter::convert( const std::string &str )
{
    e_type type = whichType(str);
    if(type == INT)
        convertInt(str); 
    // else if(type == CHAR)
    //     convertChar(str);
    // else if(type == DOUBLE)
    //     convertDouble(str);
    // else if(type == FLOAT)
    //     convertFloat(str);
    // else
    //     convertNone( void );
}
