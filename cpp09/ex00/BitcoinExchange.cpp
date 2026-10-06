/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 14:39:33 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/06 16:51:37 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


// BitcoinExchange::BitcoinExchange( const BitcoinExchange& copy )
// {
    
// }
// BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
// {
    
// }
void BitcoinExchange::displayDataBase( void )
{
    for(std::map<std::string, float>::iterator it = _chain.begin() ; it != _chain.end() ; ++it)
    {
        std::cout << "Date : " << it->first << " | Taux : " << it->second << std::endl;
    }
}



bool BitcoinExchange::loadDataBase( void )
{
    std::ifstream infile ("data.csv");
    std::string line;
    
    if(!infile.is_open())
        return false;

    std::getline(infile, line);
    while(std::getline(infile, line))
    {
        int pos = line.find(',');
        std::string date = line.substr(0, pos);
        _chain[date] = strtof(line.substr(pos+1).c_str(), NULL);
    }
    return true;

}

bool BitcoinExchange::displayInput( void )
{
    //Lignes en trop au debut ? 
    //parsing de la date : 
    //Vide au debut ou annee directement 2013 a 2022
    //Tiret 
    //atoi() 1 a 12
    //Tiret
    //01 a 31
    
    std::string line;
    while(std::getline(in, line))
    {
        std::string date = line.substr(0, line.find('|'));
        std::string parseDate();
    }
}
bool BitcoinExchange::checkInput( std::ifstream& in )
{
    if (!in.is_open())
        return false;
    in.seekg(0, std::ios::end);
    if ( in.tellg() == 0 )
        return false;
    in.seekg(0, std::ios::beg);
    return true;       
}


BitcoinExchange::BitcoinExchange( std::ifstream& in )
{
    if(checkInput(in) == false)
        throw InputException();
    if(loadDataBase() == false)
        throw DataBaseException();
    displayDataBase();        
}

// void BitcoinExchange::callEverything( void )
// {
    
// }
// std::string BitcoinExchange::parse( void )
// {
    
// } 
// void BitcoinExchange::display( void )
// {
    
// }