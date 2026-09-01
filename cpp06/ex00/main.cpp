/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:59:44 by jmetayer          #+#    #+#             */
/*   Updated: 2026/09/01 13:38:25 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int argc, char **argv )
{
    if(argc != 2)
    {    
        std::cout << "This program is supposed to take one and only one argument" << std::endl; 
        return 0;
    }
    std::string str = argv[1];
    ScalarConverter::convert(str);
    return 0;
}