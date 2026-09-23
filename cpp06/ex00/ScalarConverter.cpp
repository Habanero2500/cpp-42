/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:59:47 by jmetayer          #+#    #+#             */
/*   Updated: 2026/09/23 15:06:18 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(const std::string &str)
{
    if(str.length() == 1 && !isdigit(str[0]))
        return true;
    return false;
}
static bool isInt ( const std::string &str )
{
    long long res(0);
    unsigned int i(0);
    int sign(1);
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign *= -1;
        i++;
    }   
    while(i < str.length())
    {
        if( str[i] < '0' || str[i] > '9')
            return false;
        res = res * 10 + (str[i] - '0');
        i++;
    }
    res *= sign;
    if(res <= INT_MAX && res >= INT_MIN)
        return true;
    return false;
} 

static bool isDouble(const std::string &str)
{
    if (str == "-inf" || str == "+inf" || str == "nan")
        return true;

    unsigned int i = 0;
    long long res(0);
    bool point = false;
    int sign(1);

    if (str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign *= - 1;
        i++;
    }
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
        res = res * 10 + (str[i] - '0');
        i++;
    }
    res *= sign;
    if(res <= DBL_MAX  && res >= DBL_MIN )
        return true;
    return false;
}

static bool isFloat(const std::string &str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return true;

    unsigned int i = 0;
    bool point = false;
    long long res(0);
    int sign(1);
    
    if (str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign *= - 1;
        i++;
    }
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
        res = res * 10 + str[i] - '0';
        i++;
    }
    res *= sign;
    if(res >= FLT_MIN || res <= FLT_MAX)
        return true;
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

static void printAll( const char c, const int i, const float f, const double d)
{
    std::cout << "Char : ";
    if (c >= 32 && c <= 126)
        std::cout << c << std::endl;
    else if (c < 32 && c >= 0)
        std::cout << "Non displayable." << std::endl;
    else
        std::cout << "Impossible." << std::endl;
    std::cout << "Int : " << i << std::endl;
    
    if (d == static_cast<int>(d))
    {
        std::cout << "Float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "Double : " <<std::fixed << std::setprecision(1) << d << std::endl;
    }
    else
    {
        std::cout << "Float :" << std::setprecision(7) << d << "f" << std::endl;
        std::cout << "Double : " << std::setprecision(15) << d << std::endl;
    }
}

static void convertChar( const std::string &str )
{
    char c(str[0]);
    int i(c);    
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    printAll(c, i, f, d);
}
static void convertInt( const std::string &str )
{
    int i = std::atoi(str.c_str());    
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    printAll(i, i, f, d);
}
static void convertFloat (const std::string &str )
{
    float f = std::strtof(str.c_str(), NULL);
    if(f != f)
    {
        std::cout << "Char : impossible" << std::endl;
        std::cout << "Int : impossible" << std::endl;
        std::cout << "Float : nanf" << std::endl;
        std::cout << "Double : nan" << std::endl;
        return;
    }
    if (f > INT_MAX || f < INT_MIN)
    {
        double d = static_cast<double>(f);
        std::cout << "Char : impossible" << std::endl;
        std::cout << "Int : impossible" << std::endl;
        std::cout << "Float : " << f << "f" << std::endl;
        std::cout << "Double : " << d << std::endl;
        return;
    }
    double d = static_cast<double>(f);
    int i = static_cast<int>(f);
    printAll(i, i, f, d);
}

static void convertDouble(const std::string &str)
{
    double d = std::strtod(str.c_str(), NULL);  
    if (d != d)
    {
        std::cout << "Char : impossible" << std::endl;
        std::cout << "Int : impossible" << std::endl;
        std::cout << "Float : nanf" << std::endl;
        std::cout << "Double : nan" << std::endl;
        return;
    }
    if (d > INT_MAX || d < INT_MIN)
    {
        float f = static_cast<float>(d);

        std::cout << "Char : impossible" << std::endl;
        std::cout << "Int : impossible" << std::endl;
        std::cout << "Float : " << f << "f" << std::endl;
        std::cout << "Double : " << d << std::endl;
        return;
    }
    float f = static_cast<float>(d);
    int i = static_cast<int>(d);
    printAll(static_cast<char>(i), i, f, d);
}

static void convertNone( void )
{
    std::cout << "Char : Impossible" << std::endl;
    std::cout << "Int : Impossible" << std::endl;
    std::cout << "Float : Impossible" << std::endl;
    std::cout << "Double : Impossible" << std::endl;
}

void ScalarConverter::convert( const std::string &str )
{
    e_type type = whichType(str);
    if(type == INT)
        convertInt(str); 
    else if(type == CHAR)
        convertChar(str);
    else if(type == DOUBLE)
        convertDouble(str);
    else if(type == FLOAT)
        convertFloat(str);
    else
        convertNone();
}
