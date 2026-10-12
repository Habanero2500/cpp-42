/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:23:47 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/12 15:28:53 by user             ###   ########.fr       */
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
#include <climits>
#include <ctime>

class PmergeMe {

public :

// PmergeMe( void );
// ~PmergeMe( void );
// PmergeMe( const PmergeMe& copy);
// PmergeMe& operator=(const PmergeMe& copy);

PmergeMe( const char* str );

int parsing( const char* str );
void displayVector( void );
int checkValue( void );
void displayList( void );
void sortPairs(int left, int right);
void mergePairs(int left, int mid, int right);
void fillTheChain( void );

void insertPending( void );
std::vector<int> jacobsthalOrder( int k );

class caracterException : public std::exception{
    
    public :
    virtual const char *what() const throw()
    {
        return "Forbidden caracter used";
    }
    
};

class maxException : public std::exception{
    
    public :
    virtual const char *what() const throw()
    {
        return "One of the input overcome INT_MAX";
    }
    
};

class parsingException : public std::exception{
    
    public :
    virtual const char *what() const throw()
    {
        return "The input contains two similar numbers";
    }
    
};
private : 

std::vector<std::pair<int,int> > _v; //first et second comme avec la map
std::list<int> _mainChain; //second container pour tout afficher
int _straggler;
bool _hasStraggler; 


};

#endif