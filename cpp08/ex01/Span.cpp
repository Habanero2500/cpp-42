/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:19:46 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/02 18:02:46 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _max(0) {
    throw ContainerTooSmall();
}

Span::Span(const Span &copy) : _max(copy._max), _v(copy._v) {}

Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
        this->_v = copy._v;

    return *this;
}

Span::~Span(void) {}

Span::Span(unsigned int i) : _max(i)
{
    if(this->_max < 2)
        throw ContainerTooSmall();
}

void Span::addNumber(int i)
{
    if ( this->_v.size() < this->_max )
        _v.push_back(i);
    else
        throw IndexOutOfBonds();
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    size_t n = static_cast<size_t>(std::distance(begin, end));
    if (_v.size() + n > _max)
        throw IndexOutOfBonds();
    _v.insert(_v.end(), begin, end);
}

long long Span::shortestSpan(void)
{
    if (this->_v.size() <= 1)
        throw SpanTooShort();
    long long mini(UINT_MAX);

    for (std::vector<int>::iterator i = this->_v.begin(); i != this->_v.end(); ++i)
    {
        for (std::vector<int>::iterator o = i + 1; o != this->_v.end(); ++o)
        {
            if ((static_cast<long long>(*i) - static_cast<long long>(*o)) < mini && (static_cast<long long>(*i) - static_cast<long long>(*o)) >= 0)
                mini = (static_cast<long long>(*i) - static_cast<long long>(*o));
            else if ((static_cast<long long>(*o) - static_cast<long long>(*i)) < mini && (static_cast<long long>(*o) - *i) >= 0)
                mini = (static_cast<long long>(*o) - *i);
            else
                continue;
        }
    }
    return (mini);
}

long long Span::longestSpan(void)
{
    if (this->_v.size() <= 1)
        throw SpanTooShort();
    long long max(0);
    for (std::vector<int>::iterator i = this->_v.begin(); i != this->_v.end(); ++i)
    {
        for (std::vector<int>::iterator o = i + 1; o != this->_v.end(); ++o)
        {
            if ((static_cast<long long>(*i) - static_cast<long long>(*o)) > max)
                max = (static_cast<long long>(*i) - static_cast<long long>(*o));
            else if ((static_cast<long long>(*o) - static_cast<long long>(*i)) > max)
                max = (static_cast<long long>(*o) - static_cast<long long>(*i));
            else
                continue;
        }
    }
    return (max);
}

void Span::displaySpan(void)
{
    for (std::vector<int>::iterator it = _v.begin(); it != this->_v.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}