/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 12:03:30 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/07 13:31:09 by jmetayer         ###   ########.fr       */
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

public :

    enum Month {
        
        LONGMONTH,
        SHORTMONTH,
        FEBRAURY,
    };


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
            return "Problem occured while opening or reading the input.";
        }
    };

        class WrongInputException : public std::exception
    {
        public :
        virtual const char *what() const throw()
        {
            return "One and only one argument needed.";
        }
    };

    // BitcoinExchange( void ){};
    // BitcoinExchange( const BitcoinExchange& copy );
    // BitcoinExchange& operator=(const BitcoinExchange& copy);
    // ~BitcoinExchange( void ){};
    
    BitcoinExchange( std::ifstream& in );
    bool argTest( int argc );
    // void callEverything( int input );
    // std::string parse( void ); 
    // void display( void );
    bool loadDataBase( void );
    void displayDataBase( void );
    
    bool checkInput( std::ifstream &in );
    void displayInput( std::ifstream &in );
    std::string parseDate( std::string raw);
    std::string checkYear(std::string year);
    std::string checkMonth( std::string month);
    std::string checkDay( std::string year, std::string month, std::string day );
    void leapYear(std::string year);

    private :
    
    std::map<std::string, float> _chain;
    bool _leap;
    Month _month;
    
    
    


};

#endif 