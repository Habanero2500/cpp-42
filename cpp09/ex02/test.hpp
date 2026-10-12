/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:23:47 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/12 22:23:04 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

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

    // **** CONSTRUCTEUR ****
    PmergeMe( const char* str );

    // **** PARSING ****
    int parsing( const char* str );
    int checkValue( void );

    // **** FORD JOHNSON ALGORITHM ****
    std::vector<int> _input;
    static std::vector<uint> jacobsthalOrder( uint val );
    template <typename C> 
    void mergeInsert( C& c );
    template <typename C> 
    double sortAndTime( C& result );


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

    bool _hasStraggler;
    int _straggler;

};

// **** TEMPLATE ****

template < typename T >
void PmergeMe::mergeInsert( T& c )
{
    // **** FIRST PART : Using recursion to create the vector of pairs to determinate both the winner and the loser. 
    // Then the container is filled with only the winners
    _straggler = 0;
    _hasStraggler = (c.size() % 2 != 0);
    
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
            _straggler = a;
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
    
    // **** SECOND PART :
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
    // 4. Chaine principale : b_1, a_1, a_2, ..., a_k
    //    (b_1 < a_1 < tous les autres : aucune comparaison necessaire)
    T chain(winners);
    chain.insert(chain.begin(), sorted[0].second);

    // 5. Insertion des b_i (i >= 2) dans l'ordre de Jacobsthal.
    std::vector<uint> order = jacobsthalOrder(sorted.size());
    for (uint n = 0; n < order.size(); ++n)
    {
        uint i = order[n];
        int a = sorted[i - 1].first;
        int b = sorted[i - 1].second;

        // Position actuelle de a_i (elle bouge a chaque insertion : on la recalcule).
        typename T::iterator limit = std::find(chain.begin(), chain.end(), a);
        // b_i < a_i : on cherche par dichotomie seulement AVANT a_i.
        typename T::iterator pos = std::lower_bound(chain.begin(), limit, b);
        chain.insert(pos, b);
    }

    // 6. Le straggler s'insere par dichotomie dans toute la chaine.
    if (_hasStraggler)
    {
        typename T::iterator pos = std::lower_bound(chain.begin(), chain.end(), _straggler);
        chain.insert(pos, _straggler);
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