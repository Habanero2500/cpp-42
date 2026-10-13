/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 12:03:30 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/13 17:46:43 by jmetayer         ###   ########.fr       */
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
    bool _leap;    

    public :

    // **** ORTHODOX CANONICAL FORM ****    
    BitcoinExchange( void ){};
    BitcoinExchange( const BitcoinExchange& copy ) : _chain(copy._chain), _leap(copy._leap){};
    BitcoinExchange& operator=(const BitcoinExchange& copy)
    {
        if(this != &copy)
        {
            _chain = copy._chain;
            _leap = copy._leap;
        }
        return *this;
    }
    ~BitcoinExchange( void ){};
    
    BitcoinExchange( std::ifstream& in );
    
    //**** DATABASE LOADING ****
    
    bool argTest( int argc );
    bool loadDataBase( void );
    void displayDataBase( void );
    
    //**** PARSING ****
    
    bool checkInput( std::ifstream &in );
    void displayInput( std::ifstream &in );
    bool parseDate( std::string raw);
    bool checkYear(std::string year);
    bool checkMonth( std::string month);
    bool checkDay( std::string year, std::string month, std::string day );
    void leapYear(std::string year);
    std::string parseValue (std::string str);
    
    //**** CONVERSION *****
    float exactDate( std::string str );
    
    
    //**** EXCEPTION *****
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
    

};

#endif 