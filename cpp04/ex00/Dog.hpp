/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:53:01 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/11 19:28:52 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : virtual public Animal {
  
    private :

    public : 
    
    Dog ( void );
    ~Dog ( void );
    Dog& operator=( const Dog& type );
    Dog (const Dog& type);
    Dog (std::string type);
    
    void makeSound( void ) const;
};



#endif