/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:41:04 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/11 19:27:34 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void )
{
    std::cout << "A new animal is created thanks to the default constructor" << std::endl;
    _type = "Unkown";
}
Animal::~Animal( void )
{
    std::cout << "Animal type " << _type << " is destroyed"
    << std::endl;
}
Animal::Animal (const Animal& other)
{
    std::cout << "Copy constructor is called to create " << other.getType() << std::endl;
    _type = other.getType();
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "The operator overload is used !" << std::endl;
    if(this != &other)
    {
        _type = other.getType();
    }
    return (*this);
}

Animal::Animal(std::string type)
{
    std::cout << "Classical constructor is used to create " << type << std::endl;
    _type = type;
}
std::string Animal::getType( void ) const 
{
    return (this->_type);
}

void Animal::makeSound ( void ) const
{
    std::cout << "I am a default Animal" << std::endl;
}