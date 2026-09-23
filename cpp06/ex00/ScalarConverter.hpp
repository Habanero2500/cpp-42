/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:59:53 by jmetayer          #+#    #+#             */
/*   Updated: 2026/09/23 14:06:05 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>
#include <cfloat>
#include <iomanip>

class ScalarConverter {
    
    private :
    ScalarConverter( void );
    ScalarConverter& operator=( const ScalarConverter& copy );
    ScalarConverter( const ScalarConverter& copy );
    ~ScalarConverter( void );
    
    public :
    static void convert( const std::string& str );

};

    enum e_type{
        INT,
        CHAR, 
        DOUBLE, 
        FLOAT,
        NONE, 
    };

#endif