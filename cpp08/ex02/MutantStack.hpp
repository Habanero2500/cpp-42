/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 17:54:04 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/03 16:48:47 by jmetayer         ###   ########.fr       */
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
    
    // Orthodox canonical form
    MutantStack( void ) {}
    ~MutantStack( void ){}
    MutantStack( const MutantStack& copy ) : std::stack<T>(copy){};
    MutantStack& operator=( const MutantStack& copy ){
        std::stack<T>::operator=(copy);
        return *this;
    };

    //No iterator in the stack itself so we define the using of iterator from other container (protected in the class stack) . 
    //If no container is precised, decque will be chosen.
    //Typedef stands for chosing the name. Typename brings the compilator to know what "it" is : a type but not chosen yet, depend on T parameter (instead of a function, a static variable or whatever). 
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator constant_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator constant_reverse_iterator;

    //The stack is a container derived from another which takes off its methods like begin() and end(). 
    //The others like push(), pop(), top(), size() and empty remain available.
    //this-> is used because c (le conteneur) is not declared but could be replaced with std::stack<T>::c
    iterator begin( void ){ 
        return this->c.begin();} 
    iterator end( void ){ 
        return this->c.end();}
    constant_iterator begin( void ) const { 
        return this->c.begin();}
    constant_iterator end( void ) const { 
        return this->c.end();}
    reverse_iterator rbegin( void ){ 
        return this->c.rbegin();}
    reverse_iterator rend( void ){ 
        return this->c.rend();}
    constant_reverse_iterator rbegin( void ) const { 
        return this->c.rbegin();}
    constant_reverse_iterator rend( void ) const { 
        return this->c.rend();}
};

#endif