/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:23:47 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/09 16:54:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdexcept>
#include <list>

class PmergeMe {

public :

PmergeMe( void );
~PmergeMe( void );
PmergeMe( const PmergeMe& copy);
PmergeMe& operator=(const PmergeMe& copy);

PmergeMe( const char* str );

int parsing( const char* str );


class parsingException : public std::exception{
    
    public :
    virtual const char *what() const throw()
    {
        return "The input does not respects the parsing standard";
    }
    
};

private : 

std::vector<std::pair<int,int>> _v; //first et second comme avec la map
std::list<int> _l; //second container pour tout afficher


};

#endif