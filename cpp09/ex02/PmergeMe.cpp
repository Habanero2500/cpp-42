/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:23:50 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/14 01:38:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// **** FORME CANONIQUE ****
PmergeMe::PmergeMe( void ) : _argument(NULL){}

PmergeMe::~PmergeMe( void ){}

PmergeMe::PmergeMe( const PmergeMe& copy ) : _input(copy._input), _argument(copy._argument){}

PmergeMe &PmergeMe::operator= (const PmergeMe& copy){
        if(this != &copy)
        {
            _input = copy._input;
            _argument = copy._argument;    
        }
    return *this;    
}

// **** ALGO UTILS ****
std::vector<uint> PmergeMe::jacobsthalOrder( uint val )
{
    std::vector<uint> order;
    uint jPrev = 1;
    uint jCur = 3;

    while (jPrev < val)
    {
        uint upper = (jCur < val) ? jCur : val;
        for (uint i = upper; i > jPrev; --i)
            order.push_back(i);
        uint next = jCur + 2 * jPrev;
        jPrev = jCur;
        jCur = next;
    }
    return order;
}


// **** FORD JOHNSON : VERSION STD::VECTOR ****
void PmergeMe::mergeInsert( std::vector<int>& c )
{
    if (c.size() < 2)
        return;
 
    // FIRST PART : on forme les paires (first = winner, second = loser),
    // puis on trie les winners en rappelant l'algorithme (recursion).
    // Paires et straggler sont LOCAUX : chaque niveau de recursion a les siens.
    bool hasStraggler = (c.size() % 2 != 0);
    int straggler = 0;
    std::vector<std::pair<int, int> > pairs;
 
    for (uint i = 0; i + 1 < c.size(); i += 2)   // acces direct par indice
    {
        if (c[i] > c[i + 1])
            pairs.push_back(std::make_pair(c[i], c[i + 1]));
        else
            pairs.push_back(std::make_pair(c[i + 1], c[i]));
    }
    if (hasStraggler)
        straggler = c[c.size() - 1];
 
    std::vector<int> winners;
    for (uint i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);
    mergeInsert(winners);
 
    // SECOND PART : on range les paires dans l'ordre des winners tries
    // (sans doublon, la valeur du winner identifie sa paire),
    // puis on place le loser du plus petit winner en tete de chaine.
    std::vector<std::pair<int, int> > sorted;
    for (uint i = 0; i < winners.size(); ++i)
    {
        for (uint j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == winners[i])
            {
                sorted.push_back(pairs[j]);
                break;
            }
        }
    }
    std::vector<int> chain(winners);
    chain.insert(chain.begin(), sorted[0].second);
 
    // THIRD PART : insertion des losers dans l'ordre de Jacobsthal.
    // lower_bound = recherche dichotomique, limitee a la zone AVANT a_i.
    std::vector<uint> order = jacobsthalOrder(sorted.size());
    for (uint n = 0; n < order.size(); ++n)
    {
        uint i = order[n];
        int a = sorted[i - 1].first;
        int b = sorted[i - 1].second;
        std::vector<int>::iterator limit = std::find(chain.begin(), chain.end(), a);
        std::vector<int>::iterator pos = std::lower_bound(chain.begin(), limit, b);
        chain.insert(pos, b);
    }
    if (hasStraggler)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }
    c = chain;
}
 
// **** FORD JOHNSON : VERSION LIST ****
// std::list n'a pas d'acces par indice : on parcourt avec des iterateurs.
void PmergeMe::mergeInsert( std::list<int>& c )
{
    if (c.size() < 2)
        return;
 
    bool hasStraggler = (c.size() % 2 != 0);
    int straggler = 0;
    std::vector<std::pair<int, int> > pairs;
 
    std::list<int>::iterator it = c.begin();
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
 
    std::list<int> winners;
    for (uint i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);
    mergeInsert(winners);
 
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
    std::list<int> chain(winners);
    chain.push_front(sorted[0].second);
 
    std::vector<uint> order = jacobsthalOrder(sorted.size());
    for (uint n = 0; n < order.size(); ++n)
    {
        uint i = order[n];
        int a = sorted[i - 1].first;
        int b = sorted[i - 1].second;
        std::list<int>::iterator limit = std::find(chain.begin(), chain.end(), a);
        std::list<int>::iterator pos = std::lower_bound(chain.begin(), limit, b);
        chain.insert(pos, b);
    }
    if (hasStraggler)
    {
        std::list<int>::iterator pos =
            std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }
    c = chain;
}
 
// **** CHRONOMETRAGE ****
// Remplissage du conteneur (data management) + tri (sorting) sont tous deux mesures.
double PmergeMe::sortAndTime( std::vector<int>& result )
{
    std::clock_t start = std::clock();
 
    result.assign(_input.begin(), _input.end());
    mergeInsert(result);
 
    std::clock_t end = std::clock();
    return static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}
 
double PmergeMe::sortAndTime( std::list<int>& result )
{
    std::clock_t start = std::clock();
 
    result.assign(_input.begin(), _input.end());
    mergeInsert(result);
 
    std::clock_t end = std::clock();
    return static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

// **** PARSING UTILS ****

int PmergeMe::checkValue( void )
{
    for (uint i = 0; i < _input.size(); ++i)
    {
        for (uint j = i + 1; j < _input.size(); ++j)
        {
            if (_input[i] == _input[j])
                return 1;
        }
    }
    return 0;
}
int PmergeMe::parsing( const char* str ) 
{
    long long res = 0;
    bool number = false;

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
            _input.push_back(static_cast<int>(res));
            res = 0;
            number = false;
        }
        if (str[i] == '\0')
            break;
    }
    if (checkValue() == 1)
        return 3;
    return 0;
}

PmergeMe::PmergeMe( const char* str ) : _argument(str)
{
    //**** PARSING ****
    int parse(parsing(str));

    switch(parse)
    {
        case 1 :
        throw caracterException();
        case 2 : 
        throw maxException();
        case 3 :
        throw parsingException();
    }

    std::cout << "Before:";
    for (uint i = 0; i < _input.size(); ++i)
        std::cout << " " << _input[i];
    std::cout << std::endl;

    //**** ALGO ****    
    std::vector<int> v;
    std::list<int> l;
    double timeVector = sortAndTime(v);
    double timeList = sortAndTime(l);

    std::cout << "After:";
    for (uint i = 0; i < v.size(); ++i)
        std::cout << " " << v[i];
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _input.size() << " elements with std::vector : " << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << _input.size() << " elements with std::list : " << timeList << " us" << std::endl;
}