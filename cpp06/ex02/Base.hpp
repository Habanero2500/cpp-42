/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 17:09:01 by jmetayer          #+#    #+#             */
/*   Updated: 2026/09/22 17:12:30 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base{

    public :
        virtual ~Base(){}; 

};


Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif