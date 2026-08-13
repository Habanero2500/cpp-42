/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:07:08 by jmetayer          #+#    #+#             */
/*   Updated: 2026/06/29 13:19:49 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


 bool is_numeric(std::string str)
{
    for(int i = 0; str[i]; i++)
    {
        if(!(str[i] >= '0' && str[i] <= '9'))
            return(false);
    }
    return (true);
}
 bool is_alphabetic(std::string str)
{
    for(int i = 0; str[i]; i++)
    {
        if(!(str[i] >= 'A' && str[i] <= 'Z') 
            && !(str[i] >='a' && str[i] <='z'))
            return(false);
    }
    return(true);
}
 bool is_alphabetic_and_space(std::string str)
{
    for(int i = 0; str[i]; i++)
    {
        if(!(str[i] >= 'A' && str[i] <= 'Z') 
            && !(str[i] >='a' && str[i] <='z') && !(str[i] == 32))
            return(false);
    }
    return(true);
}

std::string display_and_add(std::string display)
{
    std::string data;
    std::cout << display;
    if (!std::getline(std::cin, data))
    {
        std::cout << "\nCtrl + D, you left the Phonebook " << std::endl;
        std::exit(0); 
    }
    return (data);
}


std::string loop(std::string str, int number)
{
    std::string result;
    
    while(1)
    {
        result = display_and_add(str);
        if(number != 1)
        {
            if (is_empty_or_whitespace(result))
            {
                std::cout << "This field cannot remain empty or contain only spaces." << std::endl;
                continue ;
            }
        }
        if(number == 0)
        {
            if(is_numeric(result) == true)
                return (result);
            else
                std::cout << "This setting can only handle digits" << std::endl;
        }
        else if(number == 1)
        {
            if(is_alphabetic_and_space(result) == true)
                return (result);
            else
                std::cout << "This setting can only handle letters and space" << std::endl;
        }
        else
        {
            if(is_alphabetic(result) == true)
                return (result);
            else
                std::cout << "This setting can only handle letters" << std::endl;
        }
    }
}

int ft_atoi(std::string str)
{   
    if(str.length() > 1)
        return(-1); 
    if (!(str[0] >= '1' && str[0] <= '8'))
        return(-1);
    int index = std::atoi(str.c_str());
    return(index);
}

bool is_empty_or_whitespace(const std::string& str) 
{
    if (str.empty()) 
    {
        return true;
    }
    for (size_t i = 0; i < str.length(); i++) 
    {
        if (std::isspace(static_cast<unsigned char>(str[i]))) {
            return true;
        }
    }
    return false ;
}



