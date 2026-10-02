/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 17:54:04 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/02 20:25:48 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


#include <iostream>
#include <stack>
#include <deque> 

template <typename T>
class MutantStack : public std::stack<T>{

    private : 
    
    public : 

    MutantStack( void ) {};
    ~MutantStack( void ){};
    MutantStack( const MutantStack& copy ){};
    MutantStack& operator=( const MutantStack& copy ){};

    typedef typename std::stack<T>::container_type::iterator it;
    //pas d'iterator dans stack donc on vient chercher celui dans le container su lequel il est calque decque
    
    template < typename T> 
    it begin( void )
    {
        return this->c.begin()
    };
    
    it end( void )
    {
        return this->c.end();
    };
};

#endif

 //push --> met un bloc au dessus 
    //pop --> le bloc du faut et supprimer 
    //top --> retourne l'element au sommet 
    //empty --> est-ce que la stack est vide
    //On doti commencer par ecrire begin ou end.
    // Comme stack est calque sur d'autre conteneur on peu aller chercher 
    
    //qu'est ce qu'un conteneur interne ?
    //qu'est ce que container_type dans typedef typename std::stack<T>::container_type::iterator iterator;
    // La stack est un deck donc l'iteratur de stack sera un iterateur de deque
    // En gros il y a un iterateur mais il n'est pas dispo d'utilisation bien que contenu dans la class parent
    //Iterator est un type 