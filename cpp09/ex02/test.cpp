/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:23:50 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/12 21:46:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "test.hpp"

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

PmergeMe::PmergeMe( const char* str )
{
    //**** PARSING ****
    int parse(parsing(str));
    if (parse == 1)
        throw caracterException();
    if (parse == 2)
        throw maxException();
    if (parse == 3)
        throw parsingException();
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