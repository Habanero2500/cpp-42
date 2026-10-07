/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 12:03:30 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/07 18:15:47 by jmetayer         ###   ########.fr       */
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

 

    //Orthodox canonicl form
    
    // BitcoinExchange( void ){};
    // BitcoinExchange( const BitcoinExchange& copy );
    // BitcoinExchange& operator=(const BitcoinExchange& copy);
    // ~BitcoinExchange( void ){};
    
    BitcoinExchange( std::ifstream& in );
    
    //Check + database loading
    
    bool argTest( int argc );
    bool loadDataBase( void );
    void displayDataBase( void );
    
    //Date parsing :
    
    bool checkInput( std::ifstream &in );
    void displayInput( std::ifstream &in );
    bool parseDate( std::string raw);
    bool checkYear(std::string year);
    bool checkMonth( std::string month);
    bool checkDay( std::string year, std::string month, std::string day );
    void leapYear(std::string year);
    
    //value parsing : 

    std::string parseValue (std::string str);
    
    //Conversion
    
    bool exactDate( std::string str );
    
    //renvoyer la valeur correspondante dans la db.
    //Est-ce qu'il faut absolument renvoyer les memes codes d'erreurs ?
    
    
    //Exception 
    

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
    
    private :
    
    std::map<std::string, float> _chain;
    bool _leap;    
    
    


};

#endif 