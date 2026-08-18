/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:52:58 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/13 14:08:23 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog ( void ) : Animal("Dog")
{
    _brain = new Brain;
    std::cout << "The dog default constructor is used" << std::endl;
}
Dog::~Dog( void )
{
    delete _brain ;
    std::cout << "A dog is destroyed" << std::endl;
}

Dog & Dog::operator=(const Dog& other)
{
    std::cout << "Dog overload operator = is called" << std::endl;
    if( this != &other)
    {
        this->_type = other.getType();
        *this->_brain = *other._brain;
    }
    return *this;
}

Dog::Dog( const Dog& other ) : Animal( other )
{
    std::cout << "Classical constructor is used to build a dog" << std::endl;
    this->_type = other.Animal::getType();
    this->_brain = new Brain(*other._brain);    
}
Dog::Dog(std::string type) : Animal( type ) 
{
    _brain = new Brain();
    std::cout << "Classical dog constructor is used to built a dog" << std::endl; 
}

void Dog::makeSound( void ) const
{
    std::cout << "Woof woof woof" << std::endl;
}

Brain* Dog::getBrain( void )
{
    return this->_brain;
}
