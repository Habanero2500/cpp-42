/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:23:50 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/09 17:21:04 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void sendTovector( int res )
{
    for(std::iterator<pair<int, int>
}

int parsing( const char* str )
{
    long long res(0);
    bool number(false);
    for( int i(0); str[i] ; i++ )
    {
        if(!(str[i] >= '0' && str[i] <= '9') || str[i] != ' ')
            return -1;
        if( str[i] >= '0' && str[i] <= '9' )
        {
            number = true;
            res *= 10 + (str[i] - '0');
            continue;
        }
        if(number == true && str[i] = ' ')
        {
            if(res > INT_MAX)
                return -1;            
            sendToVector(res);
        }
        number = false;
    }
    //check si inférieur à int max 
    //check si 
    
}

PmergeMe::PmergeMe( const char* str )
{
   if(parsing(str) == -1)
        throw parsingException();
    
}
