/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 12:03:30 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/06 16:30:53 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange{
    
private :
    
    std::map<std::string, float> _chain;

public :


    class DataBaseException : public std::exception
    {
        public :
        virtual const char *what() const throw()
        {
            return "Impossible to open the data base.";
        }
    };

    class InputException : public std::exception
    {
        public :
        virtual const char *what() const throw()
        {
            return "Problem with opening or reading the input";
        }
    };

    // BitcoinExchange( void ){};
    // BitcoinExchange( const BitcoinExchange& copy );
    // BitcoinExchange& operator=(const BitcoinExchange& copy);
    // ~BitcoinExchange( void ){};
    
    BitcoinExchange( std::ifstream& in );
    // void callEverything( int input );
    // std::string parse( void ); 
    // void display( void );
    bool loadDataBase( void );
    void displayDataBase( void );
    
    bool checkInput( std::ifstream &in );
    bool displayInput( void );
    

};

#endif 