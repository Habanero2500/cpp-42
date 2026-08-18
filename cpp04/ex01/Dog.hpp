/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:53:01 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/13 12:53:42 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal {
  
    private :
    
    Brain *_brain;

    public : 
    
    Dog ( void );
    ~Dog ( void );
    Dog& operator=( const Dog& type );
    Dog (const Dog& type);
    Dog (std::string type);
    
    void makeSound( void ) const;
    Brain* getBrain ( void );
};



#endif