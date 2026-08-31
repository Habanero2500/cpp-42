/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:59:53 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/31 18:18:18 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>

class ScalarConverter {
    
    private :
    ScalarConverter( void );
    ScalarConverter& operator=( const ScalarConverter& copy );
    ScalarConverter( const ScalarConverter& copy );
    ~ScalarConverter( void );
    
    public :
    static void convert( std::string str );

};

bool isChar(const std::string &str);
bool isInt (const std::string &str);


#endif