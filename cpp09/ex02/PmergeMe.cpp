/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:23:50 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/10 16:05:00 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::checkValue(void)
{
    for (std::vector<std::pair<int, int> >::iterator it = _v.begin(); it != _v.end(); ++it)
    {
        int val1 = it->first;
        int val2 = it->second;
        
        if (val1 == val2)
            return 1;
        for (std::vector<std::pair<int, int> >::iterator iter = it + 1; iter != _v.end(); ++iter)
        {
            if (val1 == iter->first || val1 == iter->second || val2 == iter->first || val2 == iter->second)
                return 1;
        }
        if (_hasStraggler && (val1 == _straggler || val2 == _straggler))
            return 1;
    }
    return 0;
}
int PmergeMe::parsing(const char* str)
{
    long long res = 0;
    bool number = false;
    int value = 0;
    bool first = false;

    for (int i = 0; ; ++i)
    {
        if (str[i] != '\0' && str[i] != ' '
            && !(str[i] >= '0' && str[i] <= '9'))
            return 1;
        if (str[i] >= '0' && str[i] <= '9')
        {
            number = true;
            res = res * 10 + (str[i] - '0');

            if (res > INT_MAX)
                return 2;

            continue;
        }
        if (number)
        {
            if (!first)
            {
                value = static_cast<int>(res);
                first = true;
            }
            else
            {
                if (res == value)
                    return 3;
                int current = static_cast<int>(res);
                if (value < current)
                    _v.push_back(std::make_pair(value, current));
                else
                    _v.push_back(std::make_pair(current, value));
                first = false;
            }
            res = 0;
            number = false;
        }
        if (str[i] == '\0')
            break;
    }
    if (first)
    {
        _straggler = value;
        _hasStraggler = true;
    }
    if (checkValue() == 1)
        return 3;
    return 0;
}

void PmergeMe::displayVector( void )
{
    for (std::vector<std::pair<int, int> >::iterator it = _v.begin() ; it != _v.end() ; ++it )
        std::cout << it->first << " " << it->second << std::endl; 
    if(_hasStraggler == 1)
        std::cout << _straggler << std::endl;
}

void PmergeMe::displayList( void )
{
    for(std::list<int>::iterator it = _mainChain.begin() ; it != _mainChain.end() ; ++it)
        std::cout << *it << " ";
}

PmergeMe::PmergeMe( const char* str ) : _straggler(0), _hasStraggler(false) 
{
    int parse(parsing(str));
   if(parse == 1)
        throw caracterException();
    if(parse == 2)
        throw maxException();
    if(parse == 3)
        throw parsingException();
    displayVector();
    
    
    
}
