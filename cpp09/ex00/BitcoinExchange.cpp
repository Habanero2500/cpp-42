/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 14:39:33 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/06 19:27:41 by jmetayer         ###   ########.fr       */
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
    //2008 2012 2016 2020
    if(year == "2008" || year == "2012" || year == "2016" || year == "2020")
    {
        this->_leap = true;
        return;
    }
    this->_leap = false;
    return;
}
std::string BitcoinExchange::checkYear( std::string year)
{
        if (year.size() != 4)
        return "Impossible to display";

    for (int i = 0; i < 4; ++i)
    {
        if (year[i] < '0' || year[i] > '9')
            return "Impossible to display";
    }

    int y = std::atoi(year.c_str());

    if (y < 2009 || y > 2022)
        return "Impossible to display";

    leapYear(year);

    return year;
    
}
std::string BitcoinExchange::checkMonth( std::string month)
{
        if (month.size() != 2)
        return "Impossible to display";

    if (month[0] < '0' || month[0] > '9' ||
        month[1] < '0' || month[1] > '9')
        return "Impossible to display";

    int m = std::atoi(month.c_str());

    if (m < 1 || m > 12)
        return "Impossible to display";

    return month;   
}
std::string BitcoinExchange::checkDay( std::string year, std::string month, std::string day)
{
       if (day.size() != 2)
        return "Impossible to display";

    if (day[0] < '0' || day[0] > '9' ||
        day[1] < '0' || day[1] > '9')
        return "Impossible to display";

    int d = std::atoi(day.c_str());
    int m = std::atoi(month.c_str());
    int y = std::atoi(year.c_str());

    int maxDay;

    if (m == 2)
    {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
            maxDay = 29;
        else
            maxDay = 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        maxDay = 30;
    else
        maxDay = 31;

    if (d < 1 || d > maxDay)
        return "Impossible to display";

    return day; 
}

std::string BitcoinExchange::parseDate(std::string raw)
{
    //Lignes en trop au debut ? 
    //parsing de la date : 
    //Vide au debut ou annee directement 2013 a 2022
    //Tiret 
    //atoi() 1 a 12
    //Tiret
    //01 a 31
    if (raw.size() != 10)
        return "Impossible to display";

    if (raw[4] != '-' || raw[7] != '-')
        return "Impossible to display";

    std::string year = raw.substr(0, 4);
    std::string month = raw.substr(5, 2);
    std::string day = raw.substr(8, 2);

    if (checkYear(year) == "Impossible to display")
        return "Impossible to display";

    if (checkMonth(month) == "Impossible to display")
        return "Impossible to display";

    if (checkDay(year, month, day) == "Impossible to display")
        return "Impossible to display";

    return raw;

}

void BitcoinExchange::displayInput( std::ifstream &in )
{
    std::string line;
    while(std::getline(in, line))
    {
        std::string date = line.substr(0, line.find('|'));
        std::cout << parseDate(date);
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

// void BitcoinExchange::callEverything( void )
// {
    
// }
// std::string BitcoinExchange::parse( void )
// {
    
// } 
// void BitcoinExchange::display( void )
// {
    
// }