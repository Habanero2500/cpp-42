/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 14:39:33 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/07 21:21:57 by jmetayer         ###   ########.fr       */
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
void BitcoinExchange::leapYear(std::string year)
{
    if(year == "2008" || year == "2012" || year == "2016" || year == "2020")
    {
        this->_leap = true;
        return;
    }
    this->_leap = false;
    return;
}
bool BitcoinExchange::checkYear( std::string year)
{
    if (year.size() != 4)
        return false;

    for (int i = 0; i < 4; ++i)
    {
        if (year[i] < '0' || year[i] > '9')
            return false;
    }
    int y = std::atoi(year.c_str());

    if (y < 2009 || y > 2022)
        return false;

    leapYear(year);
    return true;
}
bool BitcoinExchange::checkMonth( std::string month)
{
    if (month.size() != 2)
        return false;

    if (month[0] < '0' || month[0] > '9' ||
        month[1] < '0' || month[1] > '9')
        return false;

    int m = std::atoi(month.c_str());

    if (m < 1 || m > 12)
        return false;

    return true;   
}
bool BitcoinExchange::checkDay( std::string year, std::string month, std::string day)
{
    if (day.size() != 2)
        return false;

    if (day[0] < '0' || day[0] > '9' ||
        day[1] < '0' || day[1] > '9')
        return false;

    int d = std::atoi(day.c_str());
    int m = std::atoi(month.c_str());
    int y = std::atoi(year.c_str());

    int maxDay(0);
    if(y < 2009 || y > 2022)
        return false;
    if(y == 2009 )
    {
        if(m == 1)
        {
            if (d < 2)
                return false;
        }    
    }
    if (m == 2)
    {
        if (_leap == true)
            maxDay = 29;
        else
            maxDay = 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        maxDay = 30;
    else
        maxDay = 31;
    if (d < 1 || d > maxDay)
        return false;
    return true; 
}

bool BitcoinExchange::parseDate(std::string raw)
{        
    if (raw.size() != 11)
        return false;
    
    if(raw[4] != '-' || raw[7] != '-' || raw[10] != ' ')
        return false;

    std::string year = raw.substr(0, 4);
    std::string month = raw.substr(5, 2);
    std::string day = raw.substr(8, 2);

    if (checkYear(year) == false)
        return false;
    if (checkMonth(month) == false)
        return false;
    if (checkDay(year, month, day) == false)
        return false;

    return true;
}


std::string BitcoinExchange::parseValue (std::string str)
{
    bool point = false;
    
    for(int i(0); str[i]; i++)
    {
        if((str[i] >= '0' || str[i] <= '9') && str[i] == '.' && str[i] == ' ')
            return "Error: not a number";
            
        if(str[i] == '.')
        {
            if(point == false)
                point = true;
            else
                return "Error: not a number";
        }    
    }
    float val(strtof(str.c_str(), NULL));
    if(val < 0)
        return "Error: not a positive number.";
    if(val > 1000)
        return "Error: too large a number.";
    return str;
}

float BitcoinExchange::exactDate(std::string str)
{
    std::map<std::string, float>::iterator it = _chain.lower_bound(str);

    if (it != _chain.end() && it->first == str)
        return it->second;
    if (it == _chain.begin())
        return 0;
    --it;
    return it->second;
}

// Parsing parfait
// Sauter la premiere ligne 
// Renvoyer Error : bad input => date si erreur de date, ne pas envoyer le reste de la ligne
// Renvoyer Error: et le type d'erreur si le nombre n'est pas bon.
// Valeur finale si date et nombre sont bons conversion

void BitcoinExchange::displayInput( std::ifstream &in )
{
    std::string line;
    bool value = false;
    
    while(std::getline(in, line))
    {
        std::string date = line.substr(0, line.find('|'));
        bool resultDate = parseDate(date);
        
        if(resultDate == false) // date pas bonne
        {
            std::cout << "Error: bad input => " << line.substr(0, line.find('|') - 1) << std::endl;
            continue;
        }   
        else // date bonne
        {
            std::string val = line.substr(line.find('|') + 1, line.size() - 12 );
            if(parseValue(val) == val) // renvoie soit la valeur soit erreur
                value = true;
            else
            {
               std::cout << parseValue(val) << std::endl;
               continue; 
            }  
        }
        if(value == true)
        {
            std::string val = line.substr(line.find('|') + 1, line.size() - 12 );
            float valf = strtof(val.c_str(), NULL);
            std::cout << line.substr(0, 10) << " => " << valf;
            std::cout << " => " << valf * exactDate(line.substr(0, line.find('|'))) << std::endl;
        }
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
    displayInput(in); 
    
}

