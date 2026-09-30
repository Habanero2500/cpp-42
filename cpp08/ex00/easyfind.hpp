/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:20:57 by jmetayer          #+#    #+#             */
/*   Updated: 2026/09/30 15:49:51 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector> 
#include <iostream>
#include <list>
#include <deque>
#include <stdexcept>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

class IndexOutOfBondsException : public std::exception
{
    public :
    virtual const char *what() const throw()
    {
        return "Index out of bounds";
    }
};


//iterator = le type interne iterator defini dans le type T. Typename est uen garantie pour le compilateur
//Traduction : on dit au compilateur que iterator sera contenu dans le template T.
template <typename T>
typename T::iterator easyfind ( T& container, int value )
{
    for(typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        if(*it == value)
            return it;
    }
    throw IndexOutOfBondsException();
}



#endif