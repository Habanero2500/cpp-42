/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:52:58 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/12 13:21:17 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog ( void ) : Animal("Dog")
{
    std::cout << "The dog default constructor is used" << std::endl;
}
Dog::~Dog( void )
{
    std::cout << "A dog is destroyed" << std::endl;
}
Dog & Dog::operator=(const Dog& other)
{
    std::cout << "Dog overload operator = is called" << std::endl;
    if( this != &other)
        this->_type = other.getType();
    return *this;
}
Dog::Dog( const Dog& other ) : Animal( other )
{
    std::cout << "Classical constructor is used to build a cat" << std::endl;
}
Dog::Dog(std::string type) : Animal( type ) 
{
    std::cout << "Classical dog constructor is used to built a dog" << std::endl; 
}
void Dog::makeSound( void ) const

{
    std::cout << "Woof woof woof" << std::endl;
}
