/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:59:47 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/31 18:15:26 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isChar(const std::string &str)
{
    if(str.length() == 1 && isalpha(str[0]))
        return true;
    return false;
}
bool isInt (const std::string &str)
{
    int i(0);
    if(str[i] == '-' || str[i] == '+')
        i++;
    while(str[i])
    {
        if( str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int main( void )
{
    std::string str;
    std::cout << "Quel test ? " << std::endl;
    std::cin >> str;
    std::cout << "Is char : " << isChar(str) << std::endl;
    std::cout << "Is int : " << isChar(str) << std::endl;

    
}

// bool isFloat(const std::string &str)
// {
    
// }
// bool isDouble(const std::string &str)
// {
    
// }

// static void convert( std::string str )
// {
    
// }
