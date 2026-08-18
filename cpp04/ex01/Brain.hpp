/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 13:40:28 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/12 16:10:56 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
  
    private: 

    std::string _ideas[100];
    
    public: 
    Brain ( void );
    ~Brain ( void );
    Brain &operator=( const Brain& brain );
    Brain( const Brain& other );
    
    void setIdeas( std::string idea, int i );
    void getIdeas( int nbr );
    
    
};


#endif


