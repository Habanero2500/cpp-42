/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:23:47 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/14 12:17:18 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <list>
#include <utility>
#include <stdexcept>
#include <climits>
#include <cstddef>
#include <ctime>

class PmergeMe {

public :


    //**** ORTHODOX CANONICAL FORM ****
    PmergeMe( void );
    PmergeMe( const PmergeMe& copy );
    PmergeMe& operator= (const PmergeMe& copy);
    ~PmergeMe( void );

    // **** CONSTRUCTEUR ****
    PmergeMe( const char* str );

    // **** PARSING ****
    int parsing( const char* str );
    int checkValue( void );

    // **** FORD JOHNSON ALGORITHM ****

    static std::vector<uint> jacobsthalOrder( uint val );
    void mergeInsert( std::vector<int>& c );
    void mergeInsert( std::list<int>& c );
    double sortAndTime( std::vector<int>& result );
    double sortAndTime( std::list<int>& result );

    // **** EXCEPTION ****
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

    std::vector<int> _input;
    const char* _argument;
};

**** TEMPLATE ****

template < typename T >
void PmergeMe::mergeInsert( T& c )
{
    // FIRST PART : Using recursion to create the vector of pairs to determinate both the winner and the loser. 
    // Then the container is filled with only the winners and then call the recursion again to sort the winners
    int straggler = 0;
    bool hasStraggler = (c.size() % 2 != 0);
    
    if (c.size() < 2)
        return;
    
    std::vector<std::pair<int, int> > pairs;
    typename T::iterator it = c.begin();
    while (it != c.end())
    {
        int a = *it;
        ++it;
        if (it == c.end())
        {
            straggler = a;
            break;
        }
        int b = *it;
        ++it;
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    T winners;
    for (uint i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);
    mergeInsert(winners);
    
    // SECOND PART : The pairs are sorted from the smallest to the biggest winner puis on rajoute le loser du plus petit winner
    std::vector<std::pair<int, int> > sorted;
    for (it = winners.begin(); it != winners.end(); ++it)
    {
        for (uint j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == *it)
            {
                sorted.push_back(pairs[j]);
                break;
            }
        }
    }
    T chain(winners);
    chain.insert(chain.begin(), sorted[0].second);

    // THIRD PART : Insertion of the smallest according to the jacobsthal order, it is interresting to  
    // notice that the lower_bound fonction is using the binary insertion to proceed
    std::vector<uint> order = jacobsthalOrder(sorted.size());
    for (uint n = 0; n < order.size(); ++n)
    {
        uint i = order[n];
        int a = sorted[i - 1].first;
        int b = sorted[i - 1].second;
        typename T::iterator limit = std::find(chain.begin(), chain.end(), a);
        typename T::iterator pos = std::lower_bound(chain.begin(), limit, b);
        chain.insert(pos, b);
    }
    if (hasStraggler)
    {
        typename T::iterator pos = std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }
    c = chain;
}

template < typename T >
double PmergeMe::sortAndTime( T& result )
{
    std::clock_t start = std::clock();

    result.assign(_input.begin(), _input.end());
    mergeInsert(result);
    std::clock_t end = std::clock();
    return static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

#endif